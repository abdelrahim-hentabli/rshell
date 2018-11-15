#ifndef PARSE_H
#define PARSE_H

#include <boost/tokenizer.hpp>
#include <sstream>
#include <string>
//#include <cstring>
#include "base.h"
#include "command.h"


class Parse {

    private:
        std::string input;
        Command* cmnd;
 
    public:
        Parse(string inpt) : input(inpt) {}
        void process();
};


void Parse::process() {
    
    std::stringstream ss(cmnd);
    std::string token;
    bool isEmpty = true;

    while (ss >> token) {
        // First argument
        if (isEmpty) {
            cmnd = new Command(token)
            isEmpty = false;
        // All other arguments
        } else {
        
        }
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
                Base* a = new Argument(tok.substr(0, tok.size() - 1));
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
