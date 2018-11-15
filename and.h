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
  
  // default ctor
  And(){
    // sets the representation to '&&'
    char a[3] = "&&";
    setRep(a);
  };

  // different representation ctor
  And(char* rep): Connector(rep){};

  // different representation and initial left hand side
  And(char* rep, Base* left): Connector(rep, left){};
  
  // run command
  bool run();
};


bool And::run(){
  
  // If a user tries to run an empty and throw an exception
  if(this->getLeft() == nullptr || this->getRight() == nullptr){
    throw("Invalid Tree");
  }
  
  // It is a valid tree
  else{
    pid_t pid = fork();
    int child_status;

    // Pid of -1 is a failure to fork
    if(pid == -1){
      perror("Fork Failed:");
      return false;
    }

    // Child process
    else if(pid == 0){
      this->getLeft()->run();
      exit(errno);
    }

    // Parent process
    else{
      waitpid(pid, &child_status, 0);
      
      // If exit was called in a child
      if(WEXITSTATUS(child_status) == 3){
        exit(3);
      }
      
      // If child ran successfully
      else if(WEXITSTATUS(child_status) == 0){
          return this->getRight()->run();
      }

      // If child was unsuccessful nothing happens
    }
  }
}

#endif
