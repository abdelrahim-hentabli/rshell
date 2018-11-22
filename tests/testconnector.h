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


