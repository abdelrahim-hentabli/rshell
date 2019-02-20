#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "base.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>

class Command : public Base {
  
private:
  std::vector<Base*> argumentList;

public:
  /* Constructors */
  Command() : Base() {}
  Command(std::string repr) : Base(repr) {}
  /* Copy Constructor */
  Command(const Command& RHS) : Base(dynamic_cast<const Base&>(RHS)) {
    this->argumentList = RHS.argumentList;
  }
  /* Assignment Operator */
  virtual Command& operator= (Command RHS) {
    swap(*this, RHS);
    return *this;
  }
  /* Processor */
  void run(int dirPipe[] = nullptr);
  /* Mutator */
  void add( Base* argument ) { argumentList.push_back(argument); }
  /* Destructor */
  ~Command() {
    for (auto basePtr : argumentList)
      if (basePtr != nullptr)
        delete basePtr;
  }
  /* Friend Function */
  friend void swap(Command& a, Command& b);
};


/* Member Function */
void Command::run(int dirPipe[]) {
  
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
  if (std::string(getRep()) == "cd"){
    write(dirPipe[1], argc[1], FILENAME_MAX);
    exit(5);
  }
  else if (std::string(getRep()) == "exit"){
    exit(3);
  }
  else if(std::string(getRep()) == "test"){ 
    if(argumentList.size() < 1 || argumentList.size() > 2){
      std::cout<<"Failed: Invalid Test Command"<<std::endl;
      exit(2);
    }
    struct stat buff; 
    if(argumentList.size() == 1){
      if(stat(argc[1], &buff)){
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
      if(std::string(argc[1]) == "-e" || std::string(argc[1]) == "-f" 
                    || std::string(argc[1]) == "-d"){
        std::cout<<"(True)"<<std::endl;
        exit(0);
      } 
      else if(S_ISREG(buff.st_mode) || S_ISDIR(buff.st_mode)){
        std::cout<<"(True)"<<std::endl;
        exit(0);
      }
      else{
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
    }
    else if(std::string(argc[1]) == "-e"){
      if(stat(argc[2], &buff)){
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
      if(S_ISREG(buff.st_mode) || S_ISDIR(buff.st_mode)){
        std::cout<<"(True)"<<std::endl;
        exit(0);
      }
      else{
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
    }
    else if(std::string(argc[1]) == "-f"){
      if(stat(argc[2], &buff)){
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
      if(S_ISREG(buff.st_mode)){
        std::cout<<"(True)"<<std::endl;
        exit(0);
      }
      else{
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
    }
    else if(std::string(argc[1]) == "-d"){
      if(stat(argc[2], &buff)){
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
      if(S_ISDIR(buff.st_mode)){
        std::cout<<"(True)"<<std::endl;
        exit(0);
      }
      else{
        std::cout<<"(False)"<<std::endl;
        exit(2);
      }
    }
    else{
      std::cout<<"Failed: Invalid Test Command"<<std::endl;
      exit(2);
    }

  }

  //otherwise run execvp
  else{
    execvp(getConstRep(), argc);
    perror("Fail:");
  }
}

/* Non-member Function */
void swap(Command& a, Command& b) {
    std::swap(a.argumentList, b.argumentList);
    swap(dynamic_cast<Base&>(a), dynamic_cast<Base&>(b));
}


#endif
