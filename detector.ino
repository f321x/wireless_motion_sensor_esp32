#include <SoftwareSerial.h>  // standard arduino library

SoftwareSerial HC12(22, 23); // HC-12 TX Pin, HC-12 RX Pin

int prev_pir = 0;  // var to save previous PIR state

void setup() {
  //Serial.begin(9600);  // Serial port to computer, for debugging
  HC12.begin(1200);  // use low baud rate for higher range, must be set via AT command
  pinMode(5, INPUT);  // input pin for PIR sensor  
}

void loop() 
{
  int counter;  // counter for sending 3 times

  counter = 0;
  if (prev_pir == 0 && digitalRead(5) == HIGH)  // if motion state changes from no motion to motion
  {
    prev_pir = 1;
    while (counter < 3)
    {
      HC12.print("A");
      counter++;
      delay(1000);
    }
  }
  else if (prev_pir == 1 && digitalRead(5) == LOW)  // if no motion is happening anymore, after motion happened
  {
    prev_pir = 0;
  }
}