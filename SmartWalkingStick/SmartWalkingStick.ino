#include "SRF05.h"

namespace Pin
{
  const uint8_t trigPin = 9;
  const uint8_t echoPin = 10;
}

SRF05 ultrasonic(Pin::echoPin,Pin::trigPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance(CM): ");
  Serial.println(ultrasonic.GetDistance());
  delay(1000);
}
