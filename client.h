#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <limits.h>

class Client{
/* Client
 * Takes input and passes it to parser
 */
  char hostName[HOST_NAME_MAX];
  char clientName[LOGIN_NAME_MAX];
public:
  Client();
  // Loop taking in input and parsing and running
  void run();
};

Client::Client(){
  gethostname(hostName, HOST_NAME_MAX);
  getlogin_r(clientName, LOGIN_NAME_MAX);
}

void Client::run(){
  std::string input;
  while(true){
    std::cout << '[' << clientName << '@' << hostName << "]:~$ ";
    getline(std::cin, input);
  }
}
#endif
