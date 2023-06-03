#include <SoftwareSerial.h>  // standard arduino library
#include <ToneESP32.h>  // https://github.com/weedmanu/ToneESP32; archived the repo on Wayback Machine (archive.org)

#define NOTE_A5  880
#define NOTE_C6  1047
#define NOTE_E6  1319

#define BUZZER_PIN 4
#define BUZZER_CHANNEL 0

SoftwareSerial HC12(23, 22); // HC-12 TX Pin, HC-12 RX Pin
ToneESP32 buzzer(BUZZER_PIN, BUZZER_CHANNEL);

void setup() {
  HC12.begin(1200);  // use low baud rate for higher range, must be set via AT command
}

void beep_alarm()  // little alarm melody
{
  buzzer.tone(NOTE_A5, 50);
  delay(50);
  buzzer.tone(NOTE_C6, 50);
  delay(50);
  buzzer.tone(NOTE_E6, 75);
}

void check_if_a(char c)  // check if the transmitted byte is 'A'
{
  if (c == 65)  // 65 is the ascii value for A
  {
    beep_alarm();  // if it is, sound the alarm melody
  }
}

void loop() 
{
  while (HC12.available())  
  {
      check_if_a(HC12.read());  // if byte is received, check it
  }
}
