
int corn_ang(SoftwareSerial serialx){

int corner_angle;
  if(serialx.available())
  {
    if(serialx.read()=='A')
    {
      corner_angle = serialx.parseInt();
    }
    else
    {
      Serial.println("Not found");
    }
  }
  return corner_angle;
}

