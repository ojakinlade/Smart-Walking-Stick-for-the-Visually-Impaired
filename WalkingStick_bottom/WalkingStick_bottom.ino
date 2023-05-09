#include "SRF05.h"

namespace Pin
{
  const uint8_t vibratorPin = 7;
  const uint8_t buzzerPin = 8;
  const uint8_t trigPin = 9;
  const uint8_t echoPin = 10;  
};

SRF05 ultrasonic(Pin::echoPin,Pin::trigPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Pin::buzzerPin,OUTPUT);
  pinMode(Pin::vibratorPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ultrasonic.GetDistance() <= 15)
  {
    //Add code to vibrate and sound the buzzer
    digitalWrite(Pin::buzzerPin,HIGH);
    digitalWrite(Pin::vibratorPin,HIGH);
  }
  else
  {
    digitalWrite(Pin::buzzerPin,LOW);
    digitalWrite(Pin::vibratorPin,LOW);
  }
}
