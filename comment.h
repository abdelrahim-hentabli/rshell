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
  Comment(Base* left): Connector("#", left){};
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
      this->getLeft()->run();
      exit(errno);
    }
  }
}

#endif
