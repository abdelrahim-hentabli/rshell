#ifndef OR_H
#define OR_H

#include "connector.h"
#include <sys/wait.h>
#include <unistd.h>


class Or: public Connector {

public:
  /* Constructors */
  Or() : Connector("||") {}
  Or(Base* left) : Connector("||", left) {}
  /* Copy Constructor */
  Or(const Or& RHS) : Connector(dynamic_cast<const Connector&>(RHS)) {}
  /* Assignment Operator */
  Or& operator= (Or RHS) {
      swap(*this, RHS);
      return *this;
  }
  /* Processor */
  void run(int dirPipe[] = nullptr);
  /* Destructor */
  ~Or() = default;

  /* Friend Function */
  friend void swap(Or& a, Or& b); 
};

/* Member Function */
void Or::run(int dirPipe[]) {
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else {
    pid_t pid = fork();
    int child_status;
    
    //fork failed
    if (pid == -1) {
      perror("Fork Failed:");
    }

    //child
    else if (pid == 0) {
      this->getLeft()->run();
      exit(errno);
    }

    //parent
    else {
      waitpid(pid, &child_status, 0);
      
      //exit was called in child
      if (WEXITSTATUS(child_status) == 3) {
        exit(3);
      }

      //child failed
      else if (WEXITSTATUS(child_status) == 2) {
          this->getRight()->run();
          exit(errno);
      }

      //child passed
      else {
        exit(errno);
      }
    }
  }
}

/* Non-member Function */
void swap(Or& a, Or& b) {
    swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}


#endif
