#include <sys/wait.h>

#include "../src/parse.h"
#include "../src/base.h"

int test_valid_parse();
int test_invalid_parse();
int test_exit_parse();
int test_valid_parse_with_argument();
int test_valid_parse_with_empty_argument();
int test_invalid_command_with_argument();


int test_valid_parse() {

    Parse prs("ls");
    Base* head = prs.process();
    int exitVal = 0;
    pid_t pid = fork();

    if (pid == 0) {
        printf("In child process\n");
        head->run();
        exit(errno);
    }
    else {
        waitpid(pid, &exitVal, 0);
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_parse() {

    Parse prs("qs");
    Base* head = prs.process();
    int exitVal = 0;
    pid_t pid = fork();

    if (pid == 0) {
        head->run();
        exit(errno);
    }
    else {
        waitpid(pid, &exitVal, 0);
        
            
    }
    return WEXITSTATUS(exitVal);
}

int test_exit_parse() {

    Parse prs("exit");
    Base* head = prs.process();
    int exitVal = 0;
    pid_t pid = fork();

    if (pid == 0) {
        head->run();
        exit(errno);
    }
    else {
        waitpid(pid, &exitVal, 0);
        
            
    }
    return WEXITSTATUS(exitVal);
}

int test_valid_parse_with_arg() {

    Parse prs("ls -a");
    Base* head = prs.process();
    int exitVal = 0;
    pid_t pid = fork();

    if (pid == 0) {
        head->run();
        exit(errno);
    }
    else {
        waitpid(pid, &exitVal, 0);
        
            
    }
    return WEXITSTATUS(exitVal);
}

int test_valid_parse_with_empty_arg() {

    Parse prs("ls ");
    Base* head = prs.process();
    int exitVal = 0;
    pid_t pid = fork();

    if (pid == 0) {
        head->run();
        exit(errno);
    }
    else {
        waitpid(pid, &exitVal, 0);
        
            
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_parse_with_arg() {

    Parse prs("qs -a");
    Base* head = prs.process();
    int exitVal = 0;
    pid_t pid = fork();

    if (pid == 0) {
        head->run();
        exit(errno);
    }
    else {
        waitpid(pid, &exitVal, 0);
        
            
    }
    return WEXITSTATUS(exitVal);
}
