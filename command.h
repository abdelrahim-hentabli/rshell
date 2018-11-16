#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "base.h"
#include <unistd.h>


class Command: public Base{
  
  private:
    std::vector<Base*> argumentList;

  public:
    /* Constructors */
    Command() : Base() {};
    Command(char* repr) : Base(repr){};
    /* Copy Constructor */
    /*
    Command(const Command RHS) {
        for (auto basePtr : RHS.argumentList) {
            Base* temp = new Argument()
                // YOU'RE NOT DONE
            this->argumentList.push_back(temp);
        }
    }
    */
    void run();
    void add(Base* argument) { argumentList.push_back(argument); };
};


void Command::run(){
  char* argc [argumentList.size() + 2];
  argc [argumentList.size() + 1] = nullptr;
  argc [0] = getRep();
  for(int i = 0; i < argumentList.size(); i++){
    argc[i + 1] = argumentList.at(i)->getRep();
  }
  if(std::string(getRep()) == "exit"){
    exit(3);
  }
  else{
    execvp(argc[0], argc);
    perror("Fail:");
  }
}

#endif
