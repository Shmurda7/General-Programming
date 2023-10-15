#include <Arduino.h>

const int ledPin = 13;

//array can contain many different values
//then arrays start with 0

//array
int numOfBlinks[] = {1,2,3,4};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int delayPeriod = 1000;
  //store 5 in the array
  numOfBlinks[0] = 5;
  //empty array [10] - is the size
  int array2[10];
  //string of characters
  char array3[] = "Derek";
  //pointer pionts first character in array
  char *str = "Bananas";

  Serial.println(str);
  String myName = "Derek Bananas";
  //print 2 strings at once
  Serial.println("Name : " + myName);
  //get length
  Serial.println(myName.length());
  //quiality
  Serial.println(myName.equals("Derek"));
  //ignore upper and lower case use this
  //--equalsIgnoreCase
  //get character at specific index/location
  Serial.println(myName.charAt(6));
  //get index that matches a chracter
  Serial.println(myName.indexOf('B'));
  //remove a block of characters inside string (start index, number afterwards removed)
  //next one prints removed things
  myName.remove(0, 6);
  Serial.println(myName);
  //replace substring with one or another (needs change, change to)
  myName.replace("nas", "s");
  Serial.println(myName);
  //prints substring (start, chracters after)
  Serial.println(myName.substring(0,3));
  //change everything to upper or lower case
  myName.toUpperCase();
  myName.toLowerCase();
  //convert string to integer or float
  String one = "1";
  int num1 = one.toInt();
  int sum = num1 + num1;
  Serial.println(sum);

  //cycle through arrays
  // start at 0, stops at 5, in incraments of 1
  for(int i = 0; i < 5; i++){
    Serial.print(array3[i]);
    
  }

  for(int i = 0; i < 4; i++){
    blinkLED(numOfBlink[i]);
    delay(delayPeriod);

  }

  //want to make LED blink 1, 2, 3, 4 times
  void blinkLED(int numOfBlicks){
    for(int j = 0; j < numOfBlinks; j++){
      digitalWrite(ledPin, HIGH);
      delay(400);
      digitalWrite(ledPin, LOW);
      delay(400);
    }
  }

}