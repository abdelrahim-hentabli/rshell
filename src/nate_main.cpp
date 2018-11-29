#include <cassert>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "base.h"
#include "argument.h"
#include "command.h"
#include "connector.h"
#include "and.h"
#include "or.h"
#include "separator.h"
#include "comment.h"

using namespace std;


int main() {

    int* test = nullptr;
    delete test;

    Argument* branch = new Argument("branch");
    Argument* status = new Argument("status");
    Argument* echo0 = new Argument("Hello World!");
    
    Argument* echo1(echo0);
    Argument* echo2 = new Argument("some argument");

    echo2 = echo1;

    /*
    Argument -a("-a");
    Argument checkout("checkout");
    Argument master("master");
    */
   
    Command A("echo");
    A.add(echo2);

    Command B("git");
    B.add(branch);
    B = A;


    pid_t pid = fork();
    
    // Bad fork
    if (pid == -1) {
        perror("Unsuccessfull Fork");
    }
   
    // Child process
    if (pid == 0) {
        printf("Executing A ...\n");
        A.run();
        exit(errno);
    }
    
    // Parent process
    if (pid > 0) {
        
        int child_status;
        waitpid(pid, &child_status, 0);
        //wait();

        string cont;
        cout << ">-----------------------------------------<" << endl;
        cout << "Executing B ..." << endl;

        B.run();

        cout << "This line will never print to console" << endl;
        exit(errno);
    }
}
