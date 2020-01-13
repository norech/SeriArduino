#ifndef SERIARDUINO_H_
# define SERIARDUINO_H_

class SeriArduino {

public:
  void    write(String);
  void    write(float);
  void    write(int);
  String  read(void);
  int     available(void);

private:
  String  readString;
  int     hasAwaitingData;
  int     isInstruction;
  char    lastCharReceived;

};

#endif /* SERIARDUINO_H_ */