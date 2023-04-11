#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include "numeric_lib.h"
#include "SRF05.h"
#include "sim800l.h"
#include "button.h"

typedef struct
{
  float latitude;
  float longitude;
}loc_t;

typedef struct
{
  char lat[5];
  char lng[5];
}locChar_t;

namespace Pin
{
  const uint8_t gpsTx = 3;
  const uint8_t gpsRx = 4;
  const uint8_t buttonPin = 5;
  const uint8_t simTx = 7;
  const uint8_t simRx = 8;
  const uint8_t trigPin = 9;
  const uint8_t echoPin = 10;
}

Button_t Button = {Pin::buttonPin,BUTTON_NOT_PRESSED,false};
loc_t loc = {0};
locChar_t locChar = {0};
//Objects
SoftwareSerial gsmSerial(Pin::simTx,Pin::simRx);
SoftwareSerial gpsSerial(Pin::gpsTx,Pin::gpsRx);
TinyGPSPlus gps;
BUTTON button(&Button);
SIM800L gsm(&gsmSerial);
SRF05 ultrasonic(Pin::echoPin,Pin::trigPin);

uint32_t prevTime;
char locStr[25] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  gpsSerial.begin(9600);
  prevTime = 0;
}

void loop() {
  gpsSerial.listen();
  if(gpsSerial.available() > 0)
  {
    if(gps.encode(gpsSerial.read()))
    {
      loc.latitude = gps.location.lat();
      loc.longitude = gps.location.lng();

      //Encode Location data into char array
      memset(locChar.lat,'\0',strlen(locChar.lat));
      memset(locChar.lng,'\0',strlen(locChar.lng));
      memset(locStr,'\0',strlen(locStr));
      FloatToString(loc.latitude,locChar.lat,2);
      FloatToString(loc.longitude,locChar.lng,2);
      strcat(locStr,"Lat: ");
      strcat(locStr,locChar.lat);
      strcat(locStr," Lng: ");
      strcat(locStr,locChar.lng);
      Serial.println(locStr);
    }
  }

  button.Poll(&Button);
  if(Button.isDebounced && !Button.prevPressed)
  {
    Button.prevPressed = true;
    digitalWrite(13,HIGH);
    gsm.SendSMS("+2347032503874",locStr);
  }
  else if(!Button.isDebounced && Button.prevPressed)
  {
    Button.prevPressed = false;
    digitalWrite(13,LOW);
  }
}
