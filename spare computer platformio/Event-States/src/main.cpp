#include <Arduino.h>
#include <EventResponder.h>

//Define some Pins
#define pushbutton 7
#define buzzer 28
#define redled 40
#define whiteled 15

int blinkstate =0;
int timespent = 0;
int lasttimechanged = 0;
int isblinking = 0;
int delaytime = 1000;
int wasbuttonpushed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushbutton, INPUT);
  pinMode(redled, OUTPUT);
}

// traditional way to check for event which sucks (didn't even work for me)
//super long code to do just a blink which is unecessary
/*
void loop() {
  // put your main code here, to run repeatedly:
  if(isblinking) {
    unsigned long curtime = millis();
    if(curtime > (lasttimechanged + delaytime)) {
      if(blinkstate == 0){
        blinkstate = 1;
        digitalWrite(redled, HIGH);
        lasttimechanged = curtime;
      } else {
        blinkstate = 0;
        digitalWrite(redled, LOW);
        lasttimechanged = curtime;
      }
    } else {
    }//Nothing
  } else {
  }
  if(wasbuttonpushed) {
    if(digitalRead(2) == LOW){
      wasbuttonpushed = 0;
    }
  } else {
  if(digitalRead(2) == HIGH) {
    wasbuttonpushed = 1;
    if(isblinking == 0) {
      isblinking = 1;
    } else {
    isblinking = 0;
    }
  } 
}
}
*/
