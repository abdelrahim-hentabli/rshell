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
        
        /*
        Connector(const Connector& RHS){
          left = copy(RHS.left);
          right = copy(RHS.right);
        }
        */
        

        /* Assignment Operator */
        /*
        Connector& operator =(const Connector& RHS){
          if (left){
            delete left;
          }
          if (right){
            delete right;
          }
          left = copy(RHS.left);
          right = copy(RHS.right);

          return this;
        }
        */


        /* Destructor */
        /*
        ~Connector(){
          if (left){
            delete left;
          }
          else if(right){
            delete right;
          }
        }
        */


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

        Base* copy(){
                    

        }

        /* Pure Virtual */
        virtual void run() = 0;
};


#endif
