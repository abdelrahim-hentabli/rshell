#ifndef INPUTOUTPUTREDIRECTAPPEND_H
#define INPUTOUTPUTREDIRECTAPPEND_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>

class InputOutputRedirect: public Connector{
public:
  InputOutputRedirect():Connector("<>"){}
  InputOutputRedirect(Base* left) : Connector("<>", left){}
  void run(int dirPipe[] = nullptr);
};

void InputOutputRedirect::run(int dirPipe[]){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int inputOutputFile = open(this->getRight()->getRep(), O_RDWR | O_APPEND |  O_CREAT, S_IREAD | S_IWRITE | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    dup2(inputOutputFile, 1);
    dup2(inputOutputFile, 0);
    this->getLeft()->run();
    exit(errno);
  }
}
#endif
