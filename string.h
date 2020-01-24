//lang::CwC
#pragma once
#include "object.h"

/**                                                                              
 * An immutable string class. Values passed in are copied and deleted            
 * upon destruction.                                                             
 */         
class String: public Object {
    public:
        // constructor that takes in a char*
        String(const char* str) {}

        // destructor
        ~String() {}

        // returns the length of the string
        int length();

        // checks for equality with another object
        bool equals(Object *other);

        // returns a new concatenated string: this + o
        virtual String* concat(String *o);

        /** Returns 0 if strings are equal, >0 if this string is larger,               
         *  <0 otherwise */                                                          
        virtual int compare(String* o);

        // returns the underlying char*
        virtual const char* get_char();

        // hash function
        int hash();                                                                              
};