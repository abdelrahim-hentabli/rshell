#ifndef BASE_H
#define BASE_H


class Base {

    private:
        char* representation;

    public:
        /* Constructors */
        Base() {}
        Base(char* rep) { this->representation = rep; }
        
        /* Accessor function */
        char* getRep() { return this->representation; }

        /* Mutator function */
        void setRep(char* rep) { this->representation = rep; }

        /* Pure Virtual functions */
        virtual bool run() = 0;
        virtual void add(Base* obj) = 0;
};


#endif
