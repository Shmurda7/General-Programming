#include <Arduino.h>

//to get platform to work you need to click the blue check mark

//learn arduino language
  //first find out how to determine off 1 axis
  //second have an LED that lights up when it is
  //have another LED light up when PID reads it to correct
  //obvious brushless motor corrects it
     //learn brushless motors
  //then attempt it on 2 axis
  //then 3 axis

  

//to do list
//collect parts from Kevin
//atempt prototype
//

const int ledPin =13;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(ledPin, OUTPUT);

//print 5,4,3,2,1 and then go and run code
 countDown(5);

 //while loop does the same thing as the for loop
 //now we try while loops
 int j = 3;
 while(j > 0){
  Serial.print(j);
    Serial.print(",");
    j--;
  } 
  //then starts ends count down and says go
  Serial.println("Go ..\n");

  //basically prints out large decimal numbers
  //when working with doubles or floats only precise to
  // 6 digits
  Serial.print("3.11111111 + 4.11111111 = ");

  Serial.println(addFloats(3.11111111, 4.11111111), 8);
  Serial.println(addDoubles(3.11111111, 4.11111111), 8);

  //additional data types
  //bool can have value of true or false
  bool canVote = true;

  Serial.print("Can I Vote? ");
  //conditions, if vote = true, then ? (output) will be yes or no
  Serial.println(((canVote == true) ? "Yes" : "No"));

  //char storing character
  chat letD = 'D';
  Serial.println(letD);

  //Other data types
  // byte : 0 - 255 gets more into binary
  //unsigned int : 0 - 65535 max int value is 32000, so for larger ints
  //long : -2,147,483,648 - 2,147,483,647  longer
  //unsigned long : 0 - 4,294,967,295 even longer
  

}

void loop() {
  //due to error we change the delayperiod
  //int delayPeriod = 100;
  //int countDir = 1;

  //initial or set value 1 time and never comes back to start at (100)
  //do samething for countDir bc it's also a function of time
  static int delayPeriod = 100;
  static int countDir = 1;

//basic LED turn on and off
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);

//new variable with the delayperiod & other delay
  countDir = checkDirChange(delayPeriod, countDir);

  /*if((delayPeriod == 1000) || (delayPeriod == 0)){
    direction *= -1; direction = direction * -1;
    -this part of the code is an if statement
    -practically saying if the delay is =1000 or 0
    then the direction changes
  }
  */
  // increase amout of delay LED turn on turn off
  delayPeriod += 100 * countDir; // dP = dp + 100 

  //print more info
  //although this creates an error of repeating same value (200)
  Serial.print("New Wait Time : ");
  Serial.println(delayPeriod);


}

//another stored function which can run seperate loops
//increase delay period between blinking, and then speed up and down
//thats what this does
int checkDirChange(int delayPeriod, int countDir){
if((delayPeriod == 1000) || (delayPeriod == 0)){
  countDir *= -1;

  if(countDir < 0){
    Serial.println("Going Down");
  }
  else {
    Serial.println("Going Up");

  }

}
return countDir;
}

//another section where once the countDown recives an int max number 
// wanted to be printed
void countDown(int max){
  //continue to exicute as long as i is greater than the i 0 value and then
  // and then with the for loop it increiments the i
  //i-- is decrementing
  for(int i = max; i > 0; i--){ //same as doing i = i + 1
  //prints the values for i
    Serial.print(i);
    Serial.print(",");
  } 
  //then starts ends count down and says go
  Serial.println("Go ..\n");

}

//ints cant have decimals but floats can
float addFloats(float num1, float num2){
  return num1 + num2;

}
//does the same thing as floats
double addDoubles(double num1, double num2){
  return num1 + num2;

}