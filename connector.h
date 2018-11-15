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
        Connector(char* rep) : Base(rep){
          left = nullptr;
          right = nullptr;
        };
        Connector(char* rep, Base* l) :
            Base::Base(rep),
            left(l), 
            right(nullptr)
            {}

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
        virtual bool run() = 0;
};


#endif
