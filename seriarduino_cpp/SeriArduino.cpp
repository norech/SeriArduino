#include <Arduino.h>
#include <HardwareSerial.h>
#include "SeriArduino.h" 

void      SeriArduino::loop(void)
{
  // Don't loop if already has awaiting data
  if (hasAwaitingData)
  {
    return;
  }

  // While has data in serial port
  while (Serial.available() > 0 && !hasAwaitingData)
  {
    lastCharReceived = Serial.read();

    if (isInstruction && lastCharReceived == '<')
    {
      hasAwaitingData = 1;
      isInstruction = 0;
    }
    else if (isInstruction)
    {
      readString += lastCharReceived;
    }
    else if (lastCharReceived == '>')
    {
      isInstruction = 1;
    }
  }
}

void      SeriArduino::write(String data)
{
  Serial.print(">");
  Serial.print(data);
  Serial.println("<");
}

void      SeriArduino::write(float data)
{
  Serial.print(">");
  Serial.print(data);
  Serial.println("<");
}

void      SeriArduino::write(int data)
{
  Serial.print(">");
  Serial.print(data);
  Serial.println("<");
}

int       SeriArduino::available(void)
{
  loop();
  return (hasAwaitingData);
}

String    SeriArduino::read(void)
{
  String  returnedReadString;

  while (!hasAwaitingData)
  {
    // wait for data (calling loop() to process incoming data)
    loop();
  }

  hasAwaitingData = 0;
  returnedReadString = readString;
  readString = "";

  return (returnedReadString);
}