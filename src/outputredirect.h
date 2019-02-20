#ifndef OUTPUTREDIRECT_H
#define OUTPUTREDIRECT_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

class OutputRedirect: public Connector{
public:
  OutputRedirect():Connector(">"){}
  OutputRedirect(Base* left) : Connector(">", left){}
  void run(int dirPipe[] = nullptr);
};

void OutputRedirect::run(int dirPipe[]){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int outputFile = open(this->getRight()->getRep(), O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    dup2(outputFile, 1);
    this->getLeft()->run();
    exit(errno);
  }
}
#endif
