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

int test_valid_bracket() {
    Parse prs("[ -e src ]");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 0);
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_no_space_bracket() {
    Parse prs("[-e src ]");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2 );
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_no_left_bracket() {
    Parse prs("-e src ]");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2 );
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_no_right_bracket() {
    Parse prs("[ -e src");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2 );
    }
    return WEXITSTATUS(exitVal);
}

int test_valid_test_bracket() {
    Parse prs("test -e src");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 0);
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_test_bracket() {
    Parse prs("test -e src ]");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2);
    }
    return WEXITSTATUS(exitVal);
}

int test_valid_precedence() {
    Parse prs("(echo A)");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 0);
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_left_precedence() {
    Parse prs("echo A)");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2);
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_right_precedence() {
    Parse prs("(echo A");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2);
    }
    return WEXITSTATUS(exitVal);
}

int test_invalid_mismatch_precedence() {
    Parse prs("((echo A)");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 2);
    }
    return WEXITSTATUS(exitVal);
}

int test_valid_long_precedence() {
    Parse prs("(echo A && ((echo B || echo C) && echo D)) || echo E");
    int exitVal = 0;
    pid_t pid = fork();
    if (pid == 0){
        Base* head = prs.process();
        head->run();
        exit(errno);
    }
    else{
        waitpid(pid, &exitVal, 0);
    }
    return WEXITSTATUS(exitVal);
}
