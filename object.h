//lang::CwC
#pragma once

// represents an object
class Object {
    public:
        // default constructor
        Object() {}

        // destructor
        virtual ~Object() {}

        // check if this object is equal to another object
        virtual bool equals(Object *other);

        // hash function
        virtual int hash();
};