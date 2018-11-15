#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <limits.h>
#include "parse.h"

class Client{
/* Client
 * Takes input and passes it to parser
 */
  char hostName[HOST_NAME_MAX];
  char clientName[LOGIN_NAME_MAX];
  Parse parse;
  Base* head;
public:
  Client();
  // Loop taking in input and parsing and running
  void run();
};

Client::Client(){
  gethostname(hostName, HOST_NAME_MAX);
  getlogin_r(clientName, LOGIN_NAME_MAX);
  parse = Parse("");
}

void Client::run(){
  std::string input;
  while(true){
    std::cout << '[' << clientName << '@' << hostName << "]:~$ ";
    getline(std::cin, input);
    parse = Parse(input);
    head = parse.process();
    head->run();
  }
}
#endif
