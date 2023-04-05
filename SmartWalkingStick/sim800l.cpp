#include <Arduino.h>
#include <SoftwareSerial.h>
#include "sim800l.h"

/**
 * @brief Initializes SIM800L module
*/
SIM800L::SIM800L(SoftwareSerial* serial,uint32_t baudRate)
{
  port = serial;
  port->begin(baudRate);
}

/**
 * @brief Send SMS to the specified phone number
*/
void SIM800L::SendSMS(char* phoneNum,char* msg)
{
  const uint8_t endOfMsgCmd = 26;
  char atCmgsCmd[27] = "AT+CMGS=\"";
  port->write("AT+CMGF=1\r\n");
  delay(250);
  strcat(atCmgsCmd,phoneNum);
  strcat(atCmgsCmd,"\"\r\n");
  port->write(atCmgsCmd);
  delay(250);
  port->write(msg);
  port->write("\r\n");
  delay(250);
  port->write(endOfMsgCmd);
  delay(250);
}
