#include <iostream>

#include "../src/command.h"


void test_valid_command(){

    Base* head = new Command("ls");
        
    pid_t pid = fork();

    if(pid = 0){
      head->run();
    }
    else{
      waitpid(pid,nullptr,0);
      delete head;
    }

}

void test_invalid_command(){
  Base* head = new Command("qs");
        
  pid_t pid = fork();

  if(pid = 0){
    head->run();
  }
  else{
    waitpid(pid,nullptr,0);
    delete head;
  }
}

void test_valid_command_with_argument(){
  Base* head = new Command("ls");
  head->add(new Argument("-a")
  pid_t pid = fork();

  if(pid = 0){
    head->run();
  }
  else{
    waitpid(pid,nullptr,0);
    delete head;
  }
}

void test_invalid_command_with_argument(){
  Base* head = new Command("qs");
  head->add(new Argument("-a")
  pid_t pid = fork();

  if(pid = 0){
    head->run();
  }
  else{
    waitpid(pid,nullptr,0);
    delete head;
  }
}
