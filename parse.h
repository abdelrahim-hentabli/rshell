#ifndef PARSE_H
#define PARSE_H

#include <sstream>
#include <string>
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
        Base* head;
        Base* currentCmnd;
        char* cStringConv(std::string text);
 
    public:
        Parse() {}
        Parse(std::string inpt) 
            : input(inpt), head(nullptr), currentCmnd(nullptr) {}
        Base* process();
};

// Private Helper Function
char* Parse::cStringConv(std::string text) {
    char* cStr = new char[text.size() + 1];
    text.copy(cStr, text.size() + 1);
    cStr[text.size()] = '\0';
    return cStr;
}


// Public Member Function
Base* Parse::process() {
    std::stringstream ss(input);
    std::string token;
    bool takeCommand = true;

    while (ss >> token) {
        // Commands
        if (takeCommand) {
            char* c = cStringConv(token);
            currentCmnd = new Command(c);
            takeCommand = false;
            // First Command
            if (head == nullptr)
                head = currentCmnd;
            // Additional Command(s)
            else
                head->add(currentCmnd);
        } 
        // Comments (pound character)
        else if (token.at(0) == '#') {
            head = new Comment(head);                   // Pass old head,
            takeCommand = true;                         // then set new head
            break;
        }
        // Separator(semi-colon)
        else if (token.at(token.size() - 1) == ';') {
            // Breaks off string from semi-colon
            if (token.size() > 1) {
                std::string subS = token.substr(0, token.size() - 1);
                Base* temp = new Argument(cStringConv(subS));
                currentCmnd->add(temp);
            }
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
            Base* temp = new Argument(cStringConv(token));
            currentCmnd->add(temp);
        } 
    }
    return head;
}


#endif
