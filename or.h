#ifndef OR_H
#define OR_H

#include "connector.h"
#include <sys/wait.h>
#include <unistd.h>

class Or: public Connector{
public:
  Or(){
    char a[3] = "||";
    setRep(a);
  };
  Or(char* rep): Connector(rep){};
  Or(char* rep, Base* left): Connector(rep, left){};
  bool run();
};

bool Or::run(){
  if(this->getLeft() == nullptr || this->getRight() == nullptr){
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
      if(WEXITSTATUS(child_status) == 2){
          return this->getRight()->run();
      }
    }
  }
}

#endif
