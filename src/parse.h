#ifndef PARSE_H
#define PARSE_H

#include <sstream>
#include <string>
#include <stack>
#include "base.h"
#include "command.h"
#include "argument.h"
#include "comment.h"
#include "separator.h"
#include "and.h"
#include "or.h"


class Parse {

private:
    std::string input;
    std::stringstream ss;
    //Base* currentCmnd;
 
public:
    /* Constructors */
    Parse() {}
    Parse(std::string inpt) 
        : input(inpt) {}
    /* Mutators */
    void setInput(std::string inpt) { 
        this->input = inpt;
        ss.clear();
    }
    Base* process();
    void preprocess();
    /* Destructor */
    ~Parse() {}
};


// Public Member Functions

Base* Parse::process() {
    preprocess();
    std::string token;
    std::stack<Base*> stck;
    bool takeCommand = true;

    while (ss >> token) {
        Base* head;
        Base* currentCmnd;
        // Pop off first element, for mutation
        if (!stck.empty()) {
            head = stck.top();
            stck.pop();
        }
        // Precedence
        if (token == "(") {
            stck.push(nullptr);
        }
        else if (token == ")") {}
        
        // Commands
        else if (takeCommand) {
            currentCmnd = new Command(token);
            takeCommand = false;
            // First Command
            if (head == nullptr)
                head = currentCmnd;
            // All other Commands
            else
                head->add(currentCmnd);
            stck.push(head);
        } 
        // Separator(semi-colon)
        else if (token == ";") {
            head = new Separator(head);         // Pass old head,
            takeCommand = true;                 // then set new head
            stck.push(head);
        }
        else if (token == "&&") { 
            head = new And(head);               // Pass old head,
            takeCommand = true;                 // then set new head
            stck.push(head);
        }
        else if (token == "||") {
            head = new Or(head);                // Pass old head,
            takeCommand = true;                 // then set new head
            stck.push(head);
        }
        // Arguments
        else {    
            Base* temp = new Argument(token);
            currentCmnd->add(temp);
            stck.push(head);
        } 
    }
    Base* tmp = stck.top();
    stck.pop();
    return tmp;
}

void Parse::preprocess(){
  input = input.substr(0, input.find("#"));
  for(int i = 0; i < input.length(); i++){ 
    if(input[i] == ';'){
      input.insert(i, " ");
      i++;
    }
    else if(input[i] == '('){
      input.insert(i+1, " ");
    }
    else if(input[i] == ')'){
      input.insert(i, " ");
      i++;
    }
  }
  ss << input;                                  // Put preprocessed input string
}                                               // into stringstream

#endif
