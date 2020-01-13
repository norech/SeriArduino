#ifndef SERIARDUINO_H
#define SERIARDUINO_H

class SeriArduino {

public:
  void write(String);
  void write(float);
  void write(int);
  String read();
  int available();
  
private:
  String returnedReadString;
  String readString;
  int hasWaitingData;
  int isInstruction;
  char lastCharReceived;
  
};

#endif // SERIARDUINO_H
