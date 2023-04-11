#include <Arduino.h>
#include "SRF05.h"

SRF05::SRF05(uint8_t echoPin,uint8_t trigPin)
{
  echo_pin = echoPin;
  trig_pin = trigPin;
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
}

uint32_t SRF05::GetDistance(void)
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  uint32_t pulseWidth = pulseIn(echo_pin,HIGH);

  return pulseWidth / 29 / 2;
}
