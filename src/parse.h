#ifndef PARSE_H
#define PARSE_H

#include <sstream>
#include <string>
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
    Base* head;
    Base* currentCmnd;
 
public:
    /* Constructors */
    Parse() {}
    Parse(std::string inpt) 
        : input(inpt), head(nullptr), currentCmnd(nullptr) {}
    /* Helper Function */
    char* cStringConv(std::string text);
    /* Mutators */
    void setInput(std::string inpt) { 
        this->input = inpt;
        if (head != nullptr) {
            delete head;
            head = nullptr;
        }
        currentCmnd = nullptr;
        ss.clear();
    }
    Base* process();
    void preprocess();
    Base* gotBracket();
    /* Destructor */
    ~Parse() { if (head != nullptr) delete head; }
};


// Public Member Functions


Base* Parse::process() {
    preprocess();
    std::string token;
    bool takeCommand = true;

    while (ss >> token) {
        // Precedence
        if (token == "(") {
            
        }
        // Commands
        if (takeCommand) {
            if(token == "["){
              currentCmnd = gotBracket();
              if(currentCmnd == nullptr){
                std::cout<<"Failed: expected ']'"<<std::endl;
                exit(2);
              }
            }
            else{
              currentCmnd = new Command(token);
            }
            takeCommand = false;
            // First Command
            if (head == nullptr)
                head = currentCmnd;
            // All other Commands
            else
                head->add(currentCmnd);
        } 
        // Separator(semi-colon)
        else if (token == ";") {
            head = new Separator(head);                 // Pass old head,
            takeCommand = true;                         // then set new head
        }
        else if (token == "&&") { 
            head = new And(head);                       // Pass old head,
            takeCommand = true;                         // then set new head 
        }
        else if (token == "||") {
            head = new Or(head);                        // Pass old head,
            takeCommand = true;                         // then set new head
        }
        // Arguments
        else {    
            Base* temp = new Argument(token);
            currentCmnd->add(temp);
        } 
    }
    return head;
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
  ss << input;
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
