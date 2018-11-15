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
 
    public:
        Parse(){};
        Parse(std::string inpt) : input(inpt) {}
        Base* process();
};


Base* Parse::process() {
    
    std::stringstream ss(input);
    std::string token;
    bool takeCommand = true;

    while (ss >> token) {
        // First argument
        if (takeCommand && token.at(token.size() - 1) == ';') {
            // Breaks off string from semi-colon
            if (token.size() > 1) {
                  std::string subs = token.substr(0, token.size() - 1);
                  char cstr[subs.size() + 1];
                  subs.copy(cstr, subs.size() + 1);
                  cstr[subs.size()] = '\0';

                  currentCmnd = new Command(cstr);
              }
              head = new Separator(";", currentCmnd);
              takeCommand = true;
        } 
        else if (takeCommand) {
            char str[token.size() + 1];
            token.copy(str, token.size() + 1);
            str[token.size()] = '\0';
            head = new Command(str);
            currentCmnd = head;
            takeCommand = false;

        // All other arguments
        } 
        else {
            // Comments (pound character)
            if (token.at(0) == '#') {
                head = new Comment("#", currentCmnd);
                takeCommand = true;
                break;
            }
            // Separator(semi-colon)
            else if (token.at(token.size() - 1) == ';') {
                // Breaks off string from semi-colon
                if (token.size() > 1) {
                    std::string subs = token.substr(0, token.size() - 1);
                    char cstr[subs.size() + 1];
                    subs.copy(cstr, subs.size() + 1);
                    cstr[subs.size()] = '\0';

                    Base* temp = new Argument(cstr);
                    currentCmnd->add(temp);
                }
                head = new Separator(";", currentCmnd);
                takeCommand = true;
            }
            else if ( token == "&&" ){
              


            }
            else if ( token == "||" ){


            }
            // Arguments
            else {    
                char cstr[token.size() + 1];
                token.copy(cstr, token.size() + 1);
                cstr[token.size()] = '\0';
                Base* temp = new Argument(cstr);
                currentCmnd->add(temp);
            }
        }
    }
    return head;
}

    // Don't need this code, c++14 or something:
    /*
    boost::tokenizer<> tokens(cmnd);
    bool isEmpty = true;

    for (auto tok : tokens) {
        // First argument
        if (isEmpty) {
            cmnd = new Command(tok);
            isEmpty = false;
        // All other arguments
        } else {
            if (tok.at(tok.size() - 1) == ';') {
                Base* a = new Argument(tok.substr(0, tok.size() - 1))
                Base* b = new Argument(';');
                cmnd->add(a);
                cmnd->add(b);
            } else {
                Base* a = new Argument(tok);
                cmnd->add(a);
            }
        }
    }
    */

    /*
    char* tokenizable = new char [input.length() + 1];
    std::strcpy(tokenizable, input.c_str());

    char* subStr = std::strtok(tokenizable, " ");

    while(subStr != NULL)
    */


#endif
