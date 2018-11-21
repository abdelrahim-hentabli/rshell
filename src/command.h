#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "base.h"
#include <unistd.h>


class Command : public Base {
  
private:
  std::vector<Base*> argumentList;

public:
  /* Constructors */
  Command() : Base() {}
  Command(char* repr) : Base(repr) {}
  /* Copy Constructor */
  Command(const Command& RHS) : Base(dynamic_cast<const Base&>(RHS)) {
    this->argumentList = RHS.argumentList;
  }
  /* Assignment Operator */
  virtual Command& operator= (Command RHS) {
    printf("Command Assn Op: START\n");
    swap(*this, RHS);
    printf("Command Assn Op: END\n");
    return *this;
  }
  /* Processor */
  void run();
  /* Mutator */
  void add( Base* argument ) { argumentList.push_back(argument); }
  /* Destructor */
  ~Command() {
    for (auto basePtr : argumentList)
      if (basePtr != nullptr)
        delete basePtr;
    printf("<COMMAND Destructor has been called>\n");
  }
  /* Friend Function */
  friend void swap(Command& a, Command& b);
};


/* Member Function */
void Command::run() {
  
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

/* Non-member Function */
void swap(Command& a, Command& b) {
    printf("Swap - START\n");
    std::swap(a.argumentList, b.argumentList);
    printf("Swap - MIDDLE\n");
    swap(dynamic_cast<Base&>(a), dynamic_cast<Base&>(b));
    printf("Swap - END\n");
}


#endif
