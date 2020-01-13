#include <Arduino.h>
#include <HardwareSerial.h>
#include "SeriArduino.h" 

void SeriArduino::loop() {
  // Don't loop if has waiting data
  if(hasWaitingData) return;
  
  // While has data in serial port
  while(Serial.available() > 0 && !hasWaitingData) {
    lastCharReceived = Serial.read();
      
    if(isInstruction) {
      if(lastCharReceived == '<') {
        hasWaitingData = 1;
        isInstruction = 0;
      } else {
        readString += lastCharReceived;
      }
    } else if(lastCharReceived == '>') {
      isInstruction = 1;
    }
      
  }    
}

void SeriArduino::write(String data) {
  Serial.print(">");
  Serial.print(data);
  Serial.println("<");
}

void SeriArduino::write(float data) {
  Serial.print(">");
  Serial.print(data);
  Serial.println("<");
}

void SeriArduino::write(int data) {
  Serial.print(">");
  Serial.print(data);
  Serial.println("<");
}

int SeriArduino::available() {
  loop();
  return hasWaitingData; 
}

String SeriArduino::read() {
  while(!hasWaitingData) {
    // wait for data (calling loop() to process incoming data)
    loop();
  }
  
  hasWaitingData = 0;
  returnedReadString = readString;
  readString = "";
  
  return returnedReadString;
}
