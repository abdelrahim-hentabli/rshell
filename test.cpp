#include <iostream>
#include "base.h"
#include "connector.h"
#include "parse.h"
#include "and.h"
#include "or.h"
#include "argument.h"
#include "command.h"
#include "separator.h"

using namespace std;


int main() {

    Base* head;
      
    head = new Command("ls");
    
    head->add(new Argument("-l"));
    Base* temp = new Separator();
    temp->add(head);
    head = temp;
    temp = new Command("qs");
    temp->add(new Argument("-l")); 
    head->add(temp);
    temp = new Or();
    temp->add(head);
    head = temp;
    temp = new Command("ls");
    temp->add(new Argument("-a")); 
    head->add(temp);
    cout << "All tests passed!" << endl;
    
    head->run();
}
