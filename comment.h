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
  Comment(Base* left): Connector("#", left){};
  void run();
};

void Comment::run(){
  //exit if invalid tree
  if (this->getLeft() == nullptr){
    exit(4);
  }
  else{
    pid_t pid = fork();
    int child_status;
    //fork failed;
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
      exit(errno);
    }
  }
}

#endif
