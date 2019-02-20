#ifndef COMMENT_H
#define COMMENT_H

#include "connector.h"
#include <sys/wait.h>
#include <unistd.h>


class Comment: public Connector{

public:
  /* Constructors */
  Comment() : Connector("#") {}
  Comment(Base* left): Connector("#", left) {}
  /* Copy Constructor */
  Comment(const Comment& RHS) : Connector(dynamic_cast<const Connector&>(RHS)) {}
  /* Assignment Operator */
  Comment& operator= (Comment RHS) {
      swap(*this, RHS);
      return *this;
  }
  /* Processor */
  void run(int dirPipe[] = nullptr);
  /* Destructor */
  ~Comment() = default;

  /* Friend Function */
  friend void swap(Comment& a, Comment& b);
};

/* Member Function */
void Comment::run(int dirPipe[]){
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
      waitpid(pid, &child_status, 0);
      
      //exit was called in child
      if (WEXITSTATUS(child_status) == 3){
        exit(3);
      }

      //child failed
      else{
        exit(WEXITSTATUS(child_status));
      }
    }
  }
}

/* Non-member Functions */
void swap(Comment& a, Comment& b) {
    swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}


#endif
