#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "base.h"


class Connector : public Base {

private:
    Base* left;
    Base* right;

public:
    /* Constructors */
    Connector() : left(nullptr), right(nullptr) {}   
    Connector(std::string rep) : Base(rep){
        left = nullptr;
        right = nullptr;
    };
    Connector(std::string rep, Base* l) :
        Base(rep),
        left(l), 
        right(nullptr) 
    {}
    /* Copy Constructor */
    Connector(const Connector& RHS) :
        Base(dynamic_cast<const Base&>(RHS)),
        left(RHS.left),
        right(RHS.right)
    {}
    /* Assignment Operator */
    virtual Connector& operator= (Connector& RHS) {        
        swap(*this, RHS);
        return *this;
    }
    /* Accessors */
    Base* getLeft() { return this->left; }
    Base* getRight() { return this->right; }
    /* Mutators */
    void setLeft(Base* l) { this->left = l; }
    void setRight(Base* r) { this->right = r; }
    void setChildren(Base* l, Base* r) {
        this->left = l;
        this->right = r;
    }
    virtual void add(Base* obj) {
        if (this->left == nullptr)
            setLeft(obj);
        else if (this->right == nullptr)
            setRight(obj);
    }
    /* Pure Virtual */
    virtual void run() = 0;
    /* Destructor */
    virtual ~Connector() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    }

    /* Friend Function */
    friend void swap(Connector& a, Connector& b) {
        swap(*(a.left), *(b.left));
        swap(*(a.right), *(b.right));
    }
};


#endif
