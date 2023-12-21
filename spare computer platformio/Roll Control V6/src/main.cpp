#include <Arduino.h>
#include <MPU9250.h>
#include <SPI.h>
#include <SD.h>
#include <TinyGPS++.h>
#include <Adafruit_BMP085.h>
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>

//Sensor Defining
MPU9250 imu(Wire, 0x68);
Adafruit_BMP085 bmp;
TinyGPSPlus gps;
static const uint32_t BuadRate = 9600;

//try doing the #dfine & DEBUG stuff from Ralph S Bacon
//varbiales for the code
double xgyro, ygyro, zgyro; 

double pitch_angle, roll_angle, yaw_angle, roll, pitch;
double old_pitch_angle, old_roll_angle, old_yaw_angle; //deg
double pitch_speed, roll_speed, yaw_speed;
double old_pitch_speed, old_roll_speed, old_yaw_speed; //deg/s

double xaccel, yaccel, zaccel; //m/s

double pres, temp;

// Time Portion
double dt = 0, old_millis = 0, curr_time = 0, prev_time = 0;

//defining the visual staters & comms ////////MAKE SURE TO GIVE PINS/////////
uint8_t push_button, passive_buzzer;
uint8_t loud_buzzer;
uint8_t red_led, white_led, yellow_led;
uint8_t solenoid_uno = 15, solenoid_dos = 14, solenoid_tres = 13, solenoid_quart = 41;
static const uint8_t rxPin = 0, txPin= 1; //Pins used for Communication
SoftwareSerial ss(rxPin, txPin);      //RX & TX in Serial

//PID Gains
double kP = 1;
double kI = 0.5;
double kD = 1;

//error
double cumulative_error = 0; //for I term
double previous_error = 0; // for D term

//File & Flash Setup
File myFile;

//functions
double pid(double yaw_angle) ;
void update_control(double new_yaw_angle, double old_yaw_angle, double dt);
void statemachine();
void displaystate(String currState);

void setup() {
  //Serial for baudrate
  Serial.begin(BuadRate);

  //Pin out for States
  pinMode(red_led, OUTPUT);
  pinMode(white_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(push_button, INPUT);
  pinMode(passive_buzzer, OUTPUT);
  pinMode(loud_buzzer, OUTPUT);
  pinMode(solenoid_uno, OUTPUT);
  pinMode(solenoid_dos, OUTPUT);
  pinMode(solenoid_tres, OUTPUT);
  pinMode(solenoid_quart, OUTPUT);

  //Starting State
  digitalWrite(passive_buzzer, LOW);
  digitalWrite(loud_buzzer, LOW);
  digitalWrite(red_led, LOW);
  digitalWrite(white_led, LOW);
  digitalWrite(yellow_led, LOW);

  imu.begin();
  // setting the accelerometer full scale range to +/-8G 
  imu.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  // setting the gyroscope full scale range to +/-500 deg/s
  imu.setGyroRange(MPU9250::GYRO_RANGE_250DPS);
  // setting DLPF bandwidth to 20 Hz
  imu.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  // setting SRD to 19 for a 50 Hz update rate
  imu.setSrd(19);

    //Data Logging Initilization
  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("SD card initialization failed!");
    while(1);
  }
  Serial.println("SD card initialized.");
  //Open the file
    myFile = SD.open("F_DATA.txt", FILE_WRITE);
  if (myFile) {
    myFile.println("Time,XAcc,YAcc,ZAcc,Roll_Speed,Pitch_Speed,Yaw_Speed,Roll_Angle,Pitch_Angle,Yaw_Angle");
    //myFile.close();
  } else {
    Serial.println("Error opening data file!");
  }

  //Initializing Sensors
  //IMU
  imu.begin();
  // setting the accelerometer full scale range to +/-8G 
  imu.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  // setting the gyroscope full scale range to +/-500 deg/s
  imu.setGyroRange(MPU9250::GYRO_RANGE_250DPS);
  // setting DLPF bandwidth to 20 Hz
  imu.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  // setting SRD to 19 for a 50 Hz update rate
  imu.setSrd(20);
  //Barometric Pressure Sensor
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
  //Starting GPS
  ss.begin(BuadRate);
}

void loop() {
  curr_time = millis();
  dt = (curr_time - prev_time)/1000;

  // Reads the Data
  imu.readSensor();
  //Acceleration (m/s)
  xaccel = imu.getAccelX_mss();
  yaccel = imu.getAccelY_mss();
  zaccel = imu.getAccelZ_mss();
  //Gyroscope (rot/s)
  roll_speed = imu.getGyroX_rads();
  pitch_speed = imu.getGyroY_rads();
  yaw_speed = imu.getGyroZ_rads();

          //Angle Math
  roll_angle = roll_angle + ((roll_speed*(180/(3.1416))) * dt);
  pitch_angle = pitch_angle + ((pitch_speed*(180/(3.1416))) * dt);
  yaw_angle = yaw_angle + ((yaw_speed*(180/(3.1416))) * dt);

  old_roll_speed = roll + ((roll_speed*(180/(3.1416))) * dt);
  old_pitch_speed = pitch + ((pitch_speed*(180/(3.1416))) * dt);

  //Complementary filter, not for Yaw b/c doesn't have one
  roll = 0.96 * old_roll_speed + 0.04 * xaccel;
  pitch = 0.96 * old_pitch_speed + 0.04 * yaccel;

  if (yaw_angle != 0){
    double new_yaw_angle = pid(yaw_angle);
    update_control(new_yaw_angle, old_yaw_angle, dt);
    old_yaw_angle = new_yaw_angle;
  }

  prev_time = curr_time;
}

void StateMachine() {
  enum class flightstate : uint8_t {
    IDLE,
    FLIGHT_MODE,
    FOUND,
  };

  static flightstate currState = flightstate::IDLE;
  static bool buttonPressed = false;

  //idle state 1 with both leds off
  switch (currState) {
    case flightstate::IDLE:
      displaystate("IDLE MODE");
      digitalWrite(red_led, LOW);
      digitalWrite(passive_buzzer, HIGH);
      delay(70);
      digitalWrite(passive_buzzer, LOW);
      delay(70);
      digitalWrite(passive_buzzer, HIGH);
      digitalWrite(white_led, HIGH);
      delay(100);
      digitalWrite(white_led, LOW);
      delay(100);
      digitalWrite(white_led, HIGH);

      if (digitalRead(push_button) == 0 && !buttonPressed) {
        buttonPressed = true;
        currState = flightstate::FLIGHT_MODE;
      }
      break;

  //state 2 with led 1 working
    case flightstate::FLIGHT_MODE:
      displaystate("FLIGHT_MODE");
      digitalWrite(white_led, LOW);
      digitalWrite(passive_buzzer, HIGH);
      delay(120);
      digitalWrite(passive_buzzer, LOW);
      delay(120);
      digitalWrite(passive_buzzer, HIGH);
      digitalWrite(red_led, HIGH);
      delay(100);
      digitalWrite(red_led, LOW);
      delay(100);
      digitalWrite(red_led, HIGH);

    Serial.print("Time: ");
    Serial.print(curr_time/1000, 3);
    Serial.print("s ");
    Serial.print("\t");
    
    //Print Statements
    Serial.print(" Roll_Angle: ");
    Serial.print(roll_angle,3); 
    Serial.print("\t");
    Serial.print(" Pitch_Angle: ");
    Serial.print(pitch_angle,3);
    Serial.print("\t");
    Serial.print(" Yaw_Angle: ");
    Serial.print(yaw_angle,3); 
    Serial.print("\t");

    Serial.print(" Roll: ");
    Serial.print(roll_speed,3); 
    Serial.print("\t");
    Serial.print(" Pitch: ");
    Serial.print(pitch_speed,3);
    Serial.print("\t");
    Serial.print(" Yaw: ");
    Serial.print(yaw_speed,3); 
    Serial.print("\t");

    //Reads Temperature
    Serial.print(" T: ");
    Serial.print(temp);
    Serial.print("\t");

    //Reads Pressure
    Serial.print(" P: ");
    Serial.print(pres);

    //brightness = EEPROM.read(0);
    //Serial.print(brightness);
    //delay(500);
    
    Serial.println();
/*
  //Reads GPS Data
    while (ss.available() > 0){
      // get the byte data from the GPS
      byte gpsData = ss.read();
      // parse the byte using the encode function
      if (gps.encode(gpsData)) {
        // if the encode function returns true, it means new GPS data is available
        // you can now access the parsed GPS data using the TinyGPS++ library functions
        Serial.print(" Lat: ");
        Serial.print(gps.location.lat(), 6);
        Serial.print(" Long: ");
        Serial.print(gps.location.lng(), 6);
        Serial.print(" # of Sats= "); 
        Serial.println(gps.satellites.value()); 
      }
    }
*/
      //Data Logging Part
    myFile = SD.open("F_DATA.txt", FILE_WRITE);
    if (myFile) {
      myFile.print(curr_time/1000, 3);
      myFile.print(",");
      myFile.print(xaccel);
      myFile.print(",");
      myFile.print(yaccel);
      myFile.print(",");
      myFile.print(zaccel);
      myFile.print(",");
      myFile.print(roll_speed);
      myFile.print(",");
      myFile.print(pitch_speed);
      myFile.print(",");
      myFile.print(yaw_speed);
      myFile.print(",");
      myFile.print(roll_angle);
      myFile.print(",");
      myFile.print(pitch_angle);
      myFile.print(",");
      myFile.print(yaw_angle);
            //Reads Temperature
      myFile.print(" T: ");
      myFile.print(temp);

      //Reads Pressure
      myFile.print(" P: ");
      myFile.print(pres);
      myFile.println();
      myFile.close();

/*
    //Reads GPS Data
      while (ss.available() > 0){
        // get the byte data from the GPS
        byte gpsData = ss.read();
        // parse the byte using the encode function
        if (gps.encode(gpsData)) {
          // if the encode function returns true, it means new GPS data is available
          // you can now access the parsed GPS data using the TinyGPS++ library functions
          myFile.print(" Lat: ");
          myFile.print(gps.location.lat(), 6);
          myFile.print(" Long: ");
          myFile.print(gps.location.lng(), 6);
          myFile.print(" # of Sats= "); 
          myFile.println(gps.satellites.value()); 
        }
      }
*/

    } else {
      Serial.println("Error opening data file!");
    }

      if (digitalRead(push_button) == 0 && !buttonPressed) {
        buttonPressed = true;
        currState = flightstate::FOUND;
      }
      break;

  //state 3 with led 2 working
    case flightstate::FOUND:
      displaystate("FOUND");
      digitalWrite(red_led, LOW);
      digitalWrite(white_led, LOW);

      if (digitalRead(push_button) == 0 && !buttonPressed) {
        buttonPressed = true;
        currState = flightstate::IDLE;
      }
      break;

    default:

      Serial.println("'Default' Switch Case reached - Error");
  }

  if (digitalRead(push_button) == 1) {
    buttonPressed = false;
  }
}

//helper to print state the system is at
void displayState(String currState) {
    static String prevState = "";

    if (currState != prevState) {
        Serial.println(currState);
        prevState = currState;
    }
}

void update_control(double new_yaw_angle, double old_yaw_angle, double dt){

  if (yaw_angle > old_yaw_angle) {
    for (double pos = old_yaw_angle; pos <= new_yaw_angle; pos += 1){
      digitalWrite(solenoid_uno, HIGH);
      digitalWrite(solenoid_dos, HIGH);
      digitalWrite(solenoid_tres, LOW);
      digitalWrite(solenoid_quart, LOW);
    }
  }
  if (yaw_angle < old_yaw_angle) {
    for (double pos = old_yaw_angle; pos >= new_yaw_angle; pos -= 1){
      digitalWrite(solenoid_tres, HIGH);
      digitalWrite(solenoid_quart, HIGH);
      digitalWrite(solenoid_uno, LOW);
      digitalWrite(solenoid_dos, LOW);
    }
  }
}

double pid(double yaw_angle) {
  
  double setpoint = 0;
  Serial.print("Setpoint: ");
  Serial.print(setpoint);
  Serial.print(",");

  Serial.print(" Angle: ");
  Serial.print(yaw_angle);
  Serial.print(",");

  Serial.print(" Speed: ");
  Serial.print(yaw_speed);
  Serial.print(",");

  double error = setpoint-yaw_angle;
  Serial.print(" Error: ");
  Serial.print(error);
  Serial.print(",");

  double p_value = error*kP;
  double i_value = cumulative_error*kI;
  double d_value = (error-previous_error)*kD;

  double pid_value = p_value+i_value+d_value;

  Serial.print(" pid_value: ");
  Serial.println(pid_value);

  cumulative_error += error;
  previous_error = error;

  double new_yaw_angle = map(pid_value, -360, 360, 0, 360);

  if (new_yaw_angle > 360){
    new_yaw_angle = 360;
  }

  if (new_yaw_angle < 0){
    new_yaw_angle = 0;
  }

  return pid_value;
}