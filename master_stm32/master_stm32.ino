#include <SoftwareSerial.h>

#define rx PA10
#define tx PA9
#define enable PA15

#define rx2 PB11
#define tx2 PB10
#define enable2 PB4


int baudrate=9600;

SoftwareSerial softSerial(rx,tx);
SoftwareSerial softSerial(rx2,tx2);

void setup(){

  Serial.begin(baudrate);
  softSerial.begin(baudrate);
  softSerial2.begin(baudrate);  
  
  pinMode(enable, OUTPUT);
  pinMode(enable2, OUTPUT);  
  softSerial.setTimeout(250); //

}

void loop(){

  digitalWrite(enable,HIGH);  
  digitalWrite(enable2,LOW);  
  int corner_angle=corn_ang(softSerial2);
  int wheel_velocity=wheel_vel(softSerial2);

//slave authentication
  softSerial.print("I");
  softSerial.print("1");  //slavenumber
  softSerial.print("A");  //wait for corner angle
  softSerial.print(corner_angle);
  softSerial.print("V");  //wait for wheel velocity
  softSerial.print(wheel_velocity);
  softSerial.print("F");

  softSerial.flush();
}


