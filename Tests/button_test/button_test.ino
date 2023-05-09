#include "button.h"

Button_t Button = {5,BUTTON_NOT_PRESSED,false};
BUTTON button(&Button);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button.Poll(&Button);
  if(Button.isDebounced && !Button.prevPressed)
  {
    Button.prevPressed = true;
    digitalWrite(13,HIGH);
  }
  else if(!Button.isDebounced && Button.prevPressed)
  {
    Button.prevPressed = false;
    digitalWrite(13,LOW);
  }
}
