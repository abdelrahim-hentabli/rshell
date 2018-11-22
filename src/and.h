#ifndef AND_H
#define AND_H

#include "connector.h"
#include <sys/wait.h>
#include <unistd.h>


class And: public Connector{
/* And Connector (&&)
 * Runs the left side, and if it passes, runs the right as well
 */

public:
  /* Constructors */
  And() : Connector("&&") {}
  And(Base* left): Connector("&&", left){};     // Initial left hand side
  /* Copy Constructor */
  And(const And& RHS) : Connector(dynamic_cast<const Connector&>(RHS)) {}
  /* Assignment Operator */
  And& operator= (And RHS) {
      swap(*this, RHS);
      return *this;
  }
  /* Processor */
  void run();
  /* Destructor */
  ~And() = default;

  /* Friend Function */
  friend void swap(And& a, And& b);
};


/* Member Function */
void And::run(){
  
  // If a user tries to run an empty and throw an exception
  if (this->getLeft() == nullptr || this->getRight() == nullptr){
    exit(4);
  }
  
  // It is a valid tree
  else{
    pid_t pid = fork();
    int child_status;

    // Pid of -1 is a failure to fork
    if (pid == -1){
      perror("Fork Failed:");
    }

    // Child process
    else if (pid == 0){
      this->getLeft()->run();
      exit(errno);
    }

    // Parent process
    else{
      waitpid(pid, &child_status, 0);
      
      // If exit was called in a child
      if (WEXITSTATUS(child_status) == 3){
        exit(3);
      }
      
      // If child ran successfully
      else if (WEXITSTATUS(child_status) == 0){
          this->getRight()->run();
          exit(errno);
      }

      // If child was unsuccessful nothing happens
      else if (WEXITSTATUS(child_status) != 2){
          exit(errno);
      }
    }
  }
}


/* Non-member Function */
void swap(And& a, And& b) {
  swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}


#endif
