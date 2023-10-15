#include <Arduino.h>
int redLED=7;
//float pi=3.14;
int dit=100;
int had=500;

//String myName="Jaime Ormeno"

void setup() {
  // put your setup code here, to run once:
pinMode(redLED,OUTPUT);// (first parameter which pin, second parameter output or input)
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(redLED,HIGH); // (use pin 13, turn it high same as on)
Serial.println("Derek sucks");
delay(dit); // have to give it an interval
digitalWrite(redLED,LOW);
Serial.println("Monkey Huevos");
delay(dit);

digitalWrite(redLED,HIGH);
delay(dit);
digitalWrite(redLED,LOW);
delay(dit);

digitalWrite(redLED,HIGH); 
delay(dit);
digitalWrite(redLED,LOW);
delay(dit);

digitalWrite(redLED,HIGH); 
delay(had);
digitalWrite(redLED,LOW);
delay(had);

digitalWrite(redLED,HIGH);
delay(had);
digitalWrite(redLED,LOW);
delay(had);

digitalWrite(redLED,HIGH); 
delay(had);
digitalWrite(redLED,LOW);
delay(had);

digitalWrite(redLED,HIGH); 
delay(dit);
digitalWrite(redLED,LOW);
delay(dit);

digitalWrite(redLED,HIGH); 
delay(dit);
digitalWrite(redLED,LOW);
delay(dit);

digitalWrite(redLED,HIGH); 
delay(dit);

digitalWrite(redLED, LOW);
delay(1000);

}