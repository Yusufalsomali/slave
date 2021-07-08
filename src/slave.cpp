/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/USER/Desktop/slave/src/slave.ino"
/*
 * Project slave
 * Description:
 * Author:
 * Date:
 */

void setup();
void receiveEvent(int howMany);
void requestEvent();
void loop();
#line 8 "c:/Users/USER/Desktop/slave/src/slave.ino"
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);
#include <Wire.h>
// slave

int b = 0;
void setup()
 {
  //init pins
  pinMode(D6, OUTPUT);
  pinMode(D7, INPUT);
  Serial.begin(9600);

  //set up as slave
  Wire.begin(0x2A);                // join i2c bus with address 
  Wire.onReceive(receiveEvent); 
  Wire.onRequest(requestEvent);
  
             
}
void receiveEvent(int howMany)
 {
  char x = Wire.read();
  //turn light on/off
  if (x == '1')
  {
   digitalWrite(D6, HIGH);
  }
  else if (x == '0')
  {
    digitalWrite(D6, LOW);
  }
  Serial.println(x);    
}

void requestEvent()
 {
  //read button and write appropriate thing to wire
  if (digitalRead(D7) == HIGH) 
  {
    Wire.write("1");
  }
  if (digitalRead(D7) == LOW) 
  {
    Wire.write("0");
  }
}


void loop()
 {
  delay(1000);
}