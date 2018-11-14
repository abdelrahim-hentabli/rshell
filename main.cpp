#include <iostream>
#include "base.h"
#include "connector.h"
#include "and.h"
#include "or.h"
#include "argument.h"
#include "command.h"

using namespace std;


int main() {
    Base* head;
    char ls[3]  = "ls";
    head = new Command(ls);
    head->add(new Argument("-l"));
    Base* temp = new Or();
    temp->add(head);
    head = temp;
    temp = new Command(ls);
    temp->add(new Argument("-a"));
    std::cout<<head->run();
}
