#ifndef PARSE_H
#define PARSE_H

#include <sstream>
#include <string>
#include <stack>
#include <vector>
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
    void printError(std::string str);
    Base* gotBracket();
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
        // Mismatched handeling
        if (token == "]") {
            printError("[");
            exit(2);
        }
        // Precedence (open)
        else if (token == "(") {
            stck.push(head);
            stck.push(nullptr);
        }
        // Precedence (close)
        else if (token == ")") {
            // Mismatched handling
            if (stck.empty()) {
                printError("(");
                exit(2);
            }
            Base* oldHead = stck.top();
            stck.pop();
            if (!oldHead)
                stck.push(head);
            else {
                oldHead->add(head);
                stck.push(oldHead);
            }
            takeCommand = false;
        }
        
        // Commands
        else if (takeCommand) {
            if (token == "[") {
                currentCmnd = gotBracket();
                if (currentCmnd == nullptr) {
                    printError("]");
                    exit(2);
                }
            }
            else
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
    // Mismatched handling
    if (stck.size() > 1) { 
        printError(")");
        exit(2);
    }
    return stck.top();
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
    ss << input;                                // Put preprocessed input string
}                                               // into stringstream

void Parse::printError(std::string str) {
    std::cout << "Error: expected '" << str << "'" << std::endl;
}

Base* Parse::gotBracket(){
  std::vector < std::string > arguments;
  Base* testCmnd = new Command("test");
  std::string token;
  while(ss >> token && (token != "&&" && token != ";" && token != "||")){
    arguments.push_back(token);
  }
  if(token == "&&" || token == ";" || token == "||"){
    std::vector < std::string > remainder;
    remainder.push_back(token);
    while(ss >> token){
      remainder.push_back(token);
    }
    ss = std::stringstream();
    for(int i = 0; i < remainder.size(); i++){
      ss << remainder.at(i) + " ";
    }
    
  }
  if(arguments.empty()){
    printError("]");
    exit(2);
  }
  if(arguments.at(arguments.size() - 1) == "]"){
    for(int i = 0; i < arguments.size() - 1; i++){
      testCmnd->add(new Argument(arguments.at(i)));
    }
  }
  else{
    return nullptr;
  }
  return testCmnd;
}
#endif
