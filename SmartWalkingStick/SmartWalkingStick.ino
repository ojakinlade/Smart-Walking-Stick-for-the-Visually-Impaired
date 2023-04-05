#include <SoftwareSerial.h>
#include "SRF05.h"
#include "sim800l.h"

namespace Pin
{
  const uint8_t trigPin = 9;
  const uint8_t echoPin = 10;
  const uint8_t simTx = 2;
  const uint8_t simRx = 3;
}

SoftwareSerial gsmSerial(Pin::simTx,Pin::simRx);
SIM800L gsm(&gsmSerial);
SRF05 ultrasonic(Pin::echoPin,Pin::trigPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gsm.SendSMS("+2347032503874","HELLO!!!!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance(CM): ");
  Serial.println(ultrasonic.GetDistance());
  delay(1000);
}
