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
  Or(Base* left): Connector("||", left){};
  void run();
};

void Or::run(){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr){
    exit(4);
  }
  else{
    pid_t pid = fork();
    int child_status;
    
    //fork failed
    if (pid == -1){
      perror("Fork Failed:");
    }

    //child
    else if (pid == 0){
      this->getLeft()->run();
      exit(errno);
    }

    //parent
    else{
      waitpid(pid, &child_status, 0);
      
      //exit was called in child
      if (WEXITSTATUS(child_status) == 3){
        exit(3);
      }

      //child failed
      else if (WEXITSTATUS(child_status) == 2){
          this->getRight()->run();
          exit(errno);
      }

      //child passed
      else{
        exit(errno);
      }
    }
  }
}

#endif
