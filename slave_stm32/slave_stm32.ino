#include <SoftwareSerial.h>
#define rx PA10
#define tx PA9
#define enable PA15

int slave1 = 1;
int baudrate=9600;

SoftwareSerial softSerial(rx,tx);

void setup(){

  Serial.begin(baudrate);
  softSerial.begin(baudrate);
  
  pinMode(enable, OUTPUT);
  
  softSerial.setTimeout(250); //

}

void loop(){
  
  digitalWrite(enable,LOW); 

  if(softSerial.available()){

    if(softSerial.read()=='I'){
      int slave_add = softSerial.parseInt();
      
      if(slave_add == slave1){
        
        int corner_angle=corn_ang(softSerial);
        int wheel_velocity=wheel_vel(softSerial);

      }
    }
  }
}