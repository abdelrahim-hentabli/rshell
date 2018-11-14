#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "base.h"
#include <unistd.h>


class Command: public Base{
  
  private:
    std::vector<Base*> argumentList;

  public:
    Command():Base(){};
    Command( char* repr ):Base(repr){};
    bool run();
    void add( Base* argument ){ argumentList.push_back(argument); };
};

bool Command::run(){
  char* argc[argumentList.size() + 2 ];
  argc[argumentList.size() + 1] = nullptr;
  argc[0] = getRep();
  for(int i = 0; i < argumentList.size(); i++){
    argc[i+1] = argumentList.at(i)->getRep();
  }
  return execvp(argc[0], argc);
}

#endif
