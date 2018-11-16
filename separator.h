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
    Separator(Base* left): Connector(";", left){};
    void run();
};

void Separator::run(){
  if(this->getLeft() == nullptr){
    exit(4);
  }
  else{
    pid_t pid = fork();
    int child_status;
    //fork failed
    if(pid == -1){
      perror("Fork Failed:");
    }

    //child process
    else if(pid == 0){
      this->getLeft()->run();
      exit(errno);
    }

    //parent process
    else{
      waitpid(pid, &child_status, 0);

      //exit was called in the child
      if(WEXITSTATUS(child_status) == 3){
        exit(3);
      }
      
      //if the right side has a command run it
      else if(getRight()){
        this->getRight()->run();
        exit(errno);
      }

      //if the right side is empty
      else{
        exit(WEXITSTATUS(child_status));
      }
    }
  }
}

#endif
