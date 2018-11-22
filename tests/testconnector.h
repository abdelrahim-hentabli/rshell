#include "../src/or.h"
#include "../src/and.h"
#include "../src/separator.h"
#include "../src/comment.h"


int test_ls_or_exit(){
  
  head = new Or();
  head->add(new Command("ls");
  head->add(new Command("exit");
  
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
  
  head = new Or();
  head->add(new Command("exit");
  head->add(new Command("ls");
  
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
  
  head = new Or();
  head->add(new Command("qs");
  head->add(new Command("exit");
  
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
  
  head = new Or();
  head->add(new Command("eqit");
  head->add(new Command("ls");
  
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
  
  head = new Or();
  head->add(new Command("eqit");
  head->add(new Command("qs");
  
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
  
  head = new And();
  head->add(new Command("ls");
  head->add(new Command("exit");
  
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
  
  head = new And();
  head->add(new Command("exit");
  head->add(new Command("ls");
  
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
  
  head = new And();
  head->add(new Command("qs");
  head->add(new Command("exit");
  
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
  
  head = new And();
  head->add(new Command("eqit");
  head->add(new Command("ls");
  
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
  
  head = new And();
  head->add(new Command("eqit");
  head->add(new Command("qs");
  
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
  
  head = new Separator();
  head->add(new Command("ls");
  head->add(new Command("exit");
  
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
  
  head = new Separator();
  head->add(new Command("exit");
  head->add(new Command("ls");
  
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
  
  head = new Separator();
  head->add(new Command("qs");
  head->add(new Command("exit");
  
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
  
  head = new Separator();
  head->add(new Command("eqit");
  head->add(new Command("ls");
  
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
  
  head = new Separator();
  head->add(new Command("eqit");
  head->add(new Command("qs");
  
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

  head = new Comment();
  head->add(new Command("exit");
  head->add(new Command("qs");
  
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

  head = new Comment();
  head->add(new Command("ls");
  head->add(new Command("qs");
  
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

  head = new Comment();
  head->add(new Command("qs");
  head->add(new Command("qs");
  
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
