#ifndef ARGUMENT_H
#define ARGUMENT_H

#include "base.h"


class Argument: public Base {
/* Basic Argument Class
 * Essentially just a wrapped char array
 */
public:
    /* Constructors */
    Argument() {}
    Argument(char* repr) : Base(repr) {} 
    /* Copy Constructor */
    Argument(const Argument& RHS) : Base(dynamic_cast<const Base&>(RHS)) {}
    /* Assignment Operator */
    Argument& operator= (Argument RHS) {
        swap(*this, RHS);
        return *this;
    }
    /* Empty functions no functionality for argument */
    void run() {}
    void add(Base*) {}
    /* Destructor */
    ~Argument() = default;


    /* Friend Function */
    friend void swap(Argument& a, Argument& b) {
        Argument temp;
        temp.setRep(a.getRep());
        a.setRep(b.getRep());
        b.setRep(temp.getRep());
    }
};


#endif
