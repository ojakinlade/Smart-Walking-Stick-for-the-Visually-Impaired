#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int gpsTx = 3, gpsRx = 4;
static const uint32_t GPSBaud = 9600;

//TinyGPS object
TinyGPSPlus gps;

//Serial connection to the GPS device
SoftwareSerial ss(gpsTx,gpsRx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(ss.available() > 0)
  {
    if(gps.encode(ss.read()))
    {
      displayInfo();
    }
  }
  if(millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo(void)
{
  Serial.print(F("Location: "));
  if(gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(),6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }
}
