#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "base.h"

class Argument: public Base{
  public:
    Argument():Base(){};
    Argument(char* repr):Base(repr){};
    bool run(){};
    void add(Base*){};
};

#endif
