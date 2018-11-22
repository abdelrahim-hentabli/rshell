#ifndef BASE_H
#define BASE_H

#include <string.h>


class Base {

private:
    char* representation;

public:
    /* Constructors */
    Base() {}
    Base(char* rep){ 
      this->representation = new char[strlen(rep) + 1];
      strncpy(this->representation, rep, strlen(rep) + 1 );
      this->representation[strlen(rep)] = '\0';
    }
    /* Copy Constructor */
    Base(const Base& RHS){
      int size = 0;
      while(RHS.representation[size]){
        size++;
      }
      representation = new char[size + 1];
      representation[size] = '\0';
      for (int i = 0; i < size; i++){
        representation[i] = RHS.representation[i];
      }
    }
    /* Assignment Operator */      
    virtual Base& operator= (Base& RHS){
      printf("Base Assgn Op: START\n");
      swap(*this, RHS);
      printf("Base Assign Op: END\n");
      return *this;
    }  
    /* Accessor function */
    char* getRep() const { return this->representation; }
    /* Mutator function */
    void setRep(char* rep) { this->representation = rep; }
    /* Pure Virtual functions */
    virtual void run() = 0;
    virtual void add(Base* obj) = 0;
    /* Destructor */
    virtual ~Base() {
      if (this->representation != nullptr)
        delete this->representation;
      printf("<BASE DESTRUCTOR has been called>\n");
    }


    /* Friend Function */
    friend void swap(Base& a, Base& b) {
      std::swap(a.representation, b.representation);
    }
};


#endif
