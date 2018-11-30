#include <iostream>

#include "../src/command.h"
#include "../src/argument.h"
#include <sys/wait.h>

int test_valid_command();
int test_invalid_command();
int test_empty_command();
int test_exit_command();
int test_valid_command_with_argument();
int test_valid_command_with_empty_argument();
int test_invalid_command_with_argument();


int test_valid_test_e_command();
int test_invalid_test_e_command();

int test_valid_test_f_command();
int test_invalid_test_f_command();

int test_valid_test_d_command();
int test_invalid_test_d_command();

int test_valid_one_argument_test_command();
int test_invalid_one_argument_test_command();

int test_zero_argument_test_command();
int test_three_argument_test_command();


int test_valid_command(){

  Base* head = new Command("ls");
  int exitVal = 0;      
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_invalid_command(){
  Base* head = new Command("qs");
  int exitVal = 0;      
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_empty_command(){

  Base* head = new Command("");
  int exitVal = 0;
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
    return WEXITSTATUS(exitVal);
  }
  return WEXITSTATUS(exitVal);
}

int test_exit_command(){

  Base* head = new Command("exit");
  int exitVal = 0;      
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_valid_command_with_argument(){
  Base* head = new Command("ls");
  head->add(new Argument("-a"));
  
  
  int exitVal = 0; 
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_valid_command_with_empty_argument(){
  Base* head = new Command("ls");
  head->add(new Argument(""));
  int exitVal = 0;
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_invalid_command_with_argument(){
  Base* head = new Command("qs");
  head->add(new Argument("-a"));
  int exitVal = 0;
  pid_t pid = fork();

  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_valid_test_e_command(){
  Base* head = new Command("test");
  head->add(new Argument("-e"));
  head->add(new Argument("/src"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_invalid_test_e_command(){
  Base* head = new Command("test");
  head->add(new Argument("-e"));
  head->add(new Argument("/s"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_valid_test_f_command(){
  Base* head = new Command("test");
  head->add(new Argument("-f"));
  head->add(new Argument("test"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_invalid_test_f_command(){
  Base* head = new Command("test");
  head->add(new Argument("-f"));
  head->add(new Argument("/src"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_valid_test_d_command(){
  Base* head = new Command("test");
  head->add(new Argument("-d"));
  head->add(new Argument("/src"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_invalid_test_d_command(){
  Base* head = new Command("test");
  head->add(new Argument("-d"));
  head->add(new Argument("test"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_valid_one_argument_test_command(){
  Base* head = new Command("test");
  head->add(new Argument("/src"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_invalid_one_argument_test_command(){
  Base* head = new Command("test");
  head->add(new Argument("/s"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_zero_argument_test_command(){
  Base* head = new Command("test");
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}

int test_three_argument_test_command(){
  Base* head = new Command("test");
  head->add(new Argument("-d"));
  head->add(new Argument("/src"));
  head->add(new Argument("FAIL"));
  int exitVal = 0;
  pid_t pid = fork();
  if(pid == 0){
    head->run();
    exit(errno);
  }
  else{
    waitpid(pid,&exitVal,0);
    delete head;
  }
  return WEXITSTATUS(exitVal);
}





