#include <Arduino.h>

PVector origin;
PVector bob;
float len;

void setup() {
  // put your setup code here, to run once:
  size(640,360);

  len=180;
  origin = new PVector(width/2,0);
  bob = new PVector(width/2,len);

}

void draw() {
  // put your main code here, to run repeatedly:
  background(255);
  
  line(origin.x,origin.y,bob.x,bob.y);
  ellipse(bob.x,bob.y,32,32);

}