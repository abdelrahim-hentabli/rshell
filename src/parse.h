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
 
public:
    /* Constructors */
    Parse() {}
    Parse(std::string inpt) : input(inpt) {}
    /* Helper Function */
    char* cStringConv(std::string text);
    /* Mutators */
    void setInput(std::string inpt) { 
        this->input = inpt;
        ss.clear();
    }
    Base* process();
    void preprocess();
    /* Destructor */
    ~Parse() = default;
};


// Public Member Functions

Base* Parse::process() {
    preprocess();
    std::string token;
    std::stack<Base*> stck;
    Base* currentCmnd = nullptr;
    bool takeCommand = true;

    while (ss >> token) {
        Base* head = nullptr;
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
    return stck.top();
}

void Parse::preprocess(){
    preprocess...\n");
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
    ss << input;                                // Put preprocessed input string
}                                               // into stringstream


#endif
