#ifndef PIPE_H
#define PIPE_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

class Pipe: public Connector{
public:
  Pipe():Connector("|"){}
  Pipe(Base* left) : Connector("|", left){}
  void run(int dirPipe[] = nullptr);
};

void Pipe::run(int dirPipe[]){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int mypipe[2];
    int child_status;
    if ( pipe(mypipe) ){
      std::cout<<"Pipe Failed"<<std::endl;
      exit(2);
    }
    pid_t pid = fork();
    if ( pid == -1){
      perror("Fork Failed:");
      exit(2);
    }
    else if ( pid == 0){
      dup2(mypipe[1], 1);
      close(mypipe[0]);
      close(mypipe[1]);
      this->getLeft()->run();
      exit(errno); 
    }
    else {
      waitpid(pid, &child_status, 0);
      if ( WEXITSTATUS(child_status) == 3){
        exit(3);
      }
      else if ( WEXITSTATUS(child_status) == 2){
        exit(2);
      }
      else {
        dup2(mypipe[0], 0);
        close(mypipe[0]);
        close(mypipe[1]);
        this->getRight()->run();
        exit(errno);
      }
    }
  }
}
#endif
