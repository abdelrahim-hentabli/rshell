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
    void run();

    //add arguments
    void add( Base* argument ){ argumentList.push_back(argument); };
};

void Command::run(){
  
  //array argc contains representation and all arguments as well as a nullptr
  char* argc [argumentList.size() + 2];
  
  //nullptr terminated array
  argc [argumentList.size() + 1] = nullptr;

  //first index is command name
  argc [0] = getRep();

  //adding following indexes are arguments
  for (int i = 0; i < argumentList.size(); i++){
    argc[i + 1] = argumentList.at(i)->getRep();
  }
  
  //if command is exit
  if (std::string(getRep()) == "exit"){
    exit(3);
  }

  //otherwise run execvp
  else{
    execvp(argc[0], argc);
    perror("Fail:");
  }
}

#endif
