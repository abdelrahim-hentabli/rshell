#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "base.h"


class Argument: public Base{
/* Basic Argument Class
 * Essentially just a wrapped char array
 */
  public:
    Argument():Base(){};
    Argument(char* repr):Base(repr){};
    
    //empty functions no functionality for argument
    bool run(){};
    void add(Base*){};
};

#endif
