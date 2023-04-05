#pragma once

class SIM800L
{
  private:
    SoftwareSerial* port;
  public:
    SIM800L(SoftwareSerial* serial,uint32_t baudRate = 9600);
    void SendSMS(char* phoneNum,char* msg);
};
