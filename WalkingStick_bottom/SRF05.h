#pragma once


class SRF05
{
  private:
    uint8_t echo_pin;
    uint8_t trig_pin;

  public:
    SRF05(uint8_t echoPin, uint8_t trigPin);
    uint32_t GetDistance(void);
};
