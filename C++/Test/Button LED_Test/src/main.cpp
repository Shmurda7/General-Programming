#include <Arduino.h>

// Constants
const int buttonPin = 41;     // the number of the pushbutton pin
const int ledPin =  20;      // the number of the LED pin
const int ledPin2 =  38;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int var = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);    
  pinMode(ledPin2, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);    
  Serial.begin(9600);
  }

void loop(){
  // read the state of the pushbutton value:
     buttonState = digitalRead(buttonPin);  
     //estado botao
     if (buttonState==HIGH && var==0){
      var=1;
      Serial.println(var);
                 }
                 else if(buttonState==HIGH && var==1){
                     var=0;
                     Serial.println(var);
                      }
    //turn LED on:    
    if(buttonState==HIGH && var==0){
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW); 
    buttonState=LOW; 
    }
    else if (buttonState==HIGH && var==1){ 
    digitalWrite(ledPin2,HIGH);
    delay(400);
    digitalWrite(ledPin2,LOW); 
    buttonState=LOW;
    }  
   if(buttonState==LOW){
     digitalWrite(ledPin, LOW);
     digitalWrite(ledPin2,LOW);
     }
   
  
 
    }