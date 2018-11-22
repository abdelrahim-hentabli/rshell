#include "../src/or.h"
#include "../src/and.h"
#include "../src/separator.h"
#include "../src/comment.h"


int test_ls_or_exit(){
  
  Base* head = new Or();
  head->add(new Command("ls"));
  head->add(new Command("exit"));
  
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

int test_exit_or_ls(){
  
  Base* head = new Or();
  head->add(new Command("exit"));
  head->add(new Command("ls"));
  
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


int test_qs_or_exit(){
  
  Base* head = new Or();
  head->add(new Command("qs"));
  head->add(new Command("exit"));
  
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


int test_eqit_or_ls(){
  
  Base* head = new Or();
  head->add(new Command("eqit"));
  head->add(new Command("ls"));
  
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

int test_eqit_or_qs(){
  
  Base* head = new Or();
  head->add(new Command("eqit"));
  head->add(new Command("qs"));
  
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


int test_ls_and_exit(){
  
  Base* head = new And();
  head->add(new Command("ls"));
  head->add(new Command("exit"));
  
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

int test_exit_and_ls(){
  
  Base* head = new And();
  head->add(new Command("exit"));
  head->add(new Command("ls"));
  
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


int test_qs_and_exit(){
  
  Base* head = new And();
  head->add(new Command("qs"));
  head->add(new Command("exit"));
  
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


int test_eqit_and_ls(){
  
  Base* head = new And();
  head->add(new Command("eqit"));
  head->add(new Command("ls"));
  
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


int test_eqit_and_qs(){
  
  Base* head = new And();
  head->add(new Command("eqit"));
  head->add(new Command("qs"));
  
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

int test_ls_sep_exit(){
  
  Base* head = new Separator();
  head->add(new Command("ls"));
  head->add(new Command("exit"));
  
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

int test_exit_sep_ls(){
  
  Base* head = new Separator();
  head->add(new Command("exit"));
  head->add(new Command("ls"));
  
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


int test_qs_sep_exit(){
  
  Base* head = new Separator();
  head->add(new Command("qs"));
  head->add(new Command("exit"));
  
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


int test_eqit_sep_ls(){
  
  Base* head = new Separator();
  head->add(new Command("eqit"));
  head->add(new Command("ls"));
  
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

int test_eqit_sep_qs(){
  
  Base* head = new Separator();
  head->add(new Command("eqit"));
  head->add(new Command("qs"));
  
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

int test_exit_comment(){

  Base* head = new Comment();
  head->add(new Command("exit"));
  head->add(new Command("qs"));
  
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

int test_ls_comment(){

  Base* head = new Comment();
  head->add(new Command("ls"));
  head->add(new Command("qs"));
  
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

int test_qs_comment(){

  Base* head = new Comment();
  head->add(new Command("qs"));
  head->add(new Command("qs"));
  
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
