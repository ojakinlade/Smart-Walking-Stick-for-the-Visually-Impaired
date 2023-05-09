#include <Arduino.h>
#include "button.h"

BUTTON::BUTTON(Button_t* pButton)
{
  pinMode(pButton->pin, INPUT);
  digitalWrite(pButton->pin, HIGH);
}

bool BUTTON::Debounce(Button_t* pButton)
{
  pButton->state = digitalRead(pButton->pin);
  if(pButton->state == BUTTON_PRESSED)
  {
    delay(10);
    if(pButton->state == BUTTON_PRESSED)
    {
      return true;
    }
  }
  return false;
}

void BUTTON::Poll(Button_t* pButton)
{
  pButton->isDebounced = BUTTON::Debounce(pButton);
}
