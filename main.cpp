#include <iostream>
#include "base.h"
#include "connector.h"
//#include "parse.h"
#include "and.h"
#include "or.h"
#include "argument.h"
#include "command.h"
#include "separator.h"

using namespace std;


int main() {

    Base* head;
    try {
      head = new Command("exit");
    
      //head->add(new Argument("-l"));
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
      head->run();
    } catch(int a) {
      std::cout<<a<<std::endl;
      return 0;
    }

    cout << "Sucessfully printing from Main!" << endl;
}
