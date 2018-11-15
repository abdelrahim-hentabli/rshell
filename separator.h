#ifndef SEPARATOR_H
#define SEPARATOR_H

#include "connector.h"
#include <sys/wait.h>
#include <unistd.h>

class Separator: public Connector{
public:
  Separator(){
    char a[2] = ";";
    setRep(a);
  };
  Separator(char* rep): Connector(rep){};
  Separator(char* rep, Base* left): Connector(rep, left){};
  bool run();
};

bool Separator::run(){
  if(this->getLeft() == nullptr){
    throw("Invalid Tree");
  }
  else{
    pid_t pid = fork();
    int child_status;
    if(pid == -1){
      perror("Fork Failed:");
      return false;
    }
    else if(pid == 0){
      this->getLeft()->run();
      exit(errno);
    }
    else{
      waitpid(pid, &child_status, 0);
      if(WEXITSTATUS(child_status) == 3){
        exit(3);
      }
      else if(!getRight()){
        this->getRight()->run();
        exit(errno);
      }
      else{
        exit(WEXITSTATUS(child_status));
      }
    }
  }
}

#endif
