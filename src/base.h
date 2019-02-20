#ifndef BASE_H
#define BASE_H

#include <string.h>


class Base {

private:
    //char* representation;
    std::string representation;

public:
    /* Constructors */
    Base() {}
    Base(std::string rep){ 
      this->representation = rep;
    }
    /* Copy Constructor */
    Base(const Base& RHS){
      this->representation = RHS.representation;
    }
    /* Assignment Operator */      
    virtual Base& operator= (Base& RHS){
      swap(*this, RHS);
      return *this;
    }  
    /* Accessor function */
    char* getRep() { return &representation[0u]; }
    const char* getConstRep(){ return this-> representation.c_str(); }
    std::string getStringRep(){ return this->representation; }
    /* Mutator function */
    void setRep(std::string rep) { this->representation = rep; }
    /* Pure Virtual functions */
    virtual void run(int dirPipe[] = nullptr) = 0;
    virtual void add(Base* obj) = 0;
    /* Destructor */
    virtual ~Base() {}

    /* Friend Function */
    friend void swap(Base& a, Base& b) {
      std::swap(a.representation, b.representation);
    }
};


#endif
