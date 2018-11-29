#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <limits.h>
#include "parse.h"
#include <iostream>

class Client{
/* Client
 * Takes input and passes it to parser
 */
  char hostName[HOST_NAME_MAX];
  char clientName[LOGIN_NAME_MAX];
  //Parse parse;
public:
  Client();
  // Loop taking in input and parsing and running
  void run();
};

Client::Client(){
  //get hostname and login name
  gethostname(hostName, HOST_NAME_MAX);
  getlogin_r(clientName, LOGIN_NAME_MAX);
}

void Client::run(){
  std::string input;
  int child_status;
  Base* head;
  while(true){
    std::cout << '[' << clientName << '@' << hostName << "]:~$ ";
    getline(std::cin, input);
    //Parse parse(input);
    Parse parse;
    parse.setInput(input);
    std::cout << "initializing head to new parse.process();" << std::endl;
    head = parse.process(); 
    pid_t pid = fork();
    if(pid == -1){
      perror("Fork Failed: ");
    }
    else if(pid == 0){
      head->run();
      exit(errno);
    }
    else{
      waitpid(pid, &child_status, 0); 
      //exit was called
      if(WEXITSTATUS(child_status) == 3){
        exit(0);
      }
      else if(WEXITSTATUS(child_status) == 4){
        std::cout<<"Invalid Tree"<<std::endl;
        exit(4);
      }
      
    }
  }
}

#endif
