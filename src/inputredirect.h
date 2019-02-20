#ifndef INPUTREDIRECT_H
#define INPUTREDIRECT_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

class InputRedirect: public Connector{
public:
  InputRedirect():Connector("<"){}
  InputRedirect(Base* left) : Connector("<", left){}
  void run(int dirPipe[] = nullptr);
};

void InputRedirect::run(int dirPipe[]){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int inputFile = open(this->getRight()->getRep(), O_RDONLY);
    dup2(inputFile, 0);
    this->getLeft()->run();
    exit(errno);
  }
}
#endif
