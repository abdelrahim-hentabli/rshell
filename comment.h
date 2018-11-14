#ifndef COMMENT_H
#define COMMENT_H

#include "connector.h"
#include <sys/wait.h>
#include <unistd.h>

class Comment: public Connector{
public:
  Comment(){
    char a[2] = "#";
    setRep(a);
  };
  Comment(char* rep): Connector(rep){};
  Comment(char* rep, Base* left): Connector(rep, left){};
  bool run();
};

bool Comment::run(){
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
      exit(this->getLeft()->run());
    }
    else{
      waitpid(pid, &child_status, 0);
      if(child_status == 1){
        return this->getRight()->run();
      }
      else{
        return false;        
      }
    }
  }
}

#endif
