#include <Arduino.h>

//definition of stuff
#define pushBtn 7

#define redLED 27
#define whtLED 24

// void functions 
void blinkredLed();
void displayState(String currState);
void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(whtLED, OUTPUT);
  pinMode(pushBtn, INPUT);

  digitalWrite(redLED, LOW);
  digitalWrite(whtLED, LOW);
}

void loop() {
    blinkredLed();
}

void blinkredLed() {
  enum class flightstate : uint8_t {
    IDLE,
    STATE2,
    STATE3,
  };

  static flightstate currState = flightstate::IDLE;
  static bool buttonPressed = false;
  static unsigned long previousMillis = 0;
  static unsigned long interval = 500;

  //idle state 1 with both leds off
  switch (currState) {
    case flightstate::IDLE:
      displayState("IDLE state");
      digitalWrite(redLED, LOW);
      digitalWrite(whtLED, LOW);

      if (digitalRead(pushBtn) == 0 && !buttonPressed) {
        buttonPressed = true;
        currState = flightstate::STATE2;
      }
      break;

  //state 2 with led 1 working
    case flightstate::STATE2:
      displayState("STATE2");
      digitalWrite(redLED, LOW);
      digitalWrite(whtLED, HIGH);
      delay(100);
      digitalWrite(whtLED, LOW);
      delay(100);
      digitalWrite(whtLED, HIGH);

      if (digitalRead(pushBtn) == 0 && !buttonPressed) {
        buttonPressed = true;
        currState = flightstate::STATE3;
      }
      break;

  //state 3 with led 2 working
    case flightstate::STATE3:
      displayState("STATE3");
      digitalWrite(whtLED, LOW);
      digitalWrite(redLED, HIGH);
      delay(100);
      digitalWrite(redLED, LOW);
      delay(100);
      digitalWrite(redLED, HIGH);


      if (digitalRead(pushBtn) == 0 && !buttonPressed) {
        buttonPressed = true;
        currState = flightstate::IDLE;
      }
      break;

    default:

      Serial.println("'Default' Switch Case reached - Error");
  }

  if (digitalRead(pushBtn) == 1) {
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