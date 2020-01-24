//lang:CwC
#include "object.h"
#include "string.h"

// Represents a Map object of Strings to Objects
// owns the values but does not copy on puts
class Map : public Object {
    public:
        // default constructor
        Map(){}
        // copy constructor
        Map(Map* m){}
        // default constructor
        virtual ~Map(){}

        // associates the value with the key in this map
        virtual void put(String *key, Object *value);
        // returns the value associated this key in the map
        Object* get(String* key);
        // checks if the map contains a value with this key
        bool contains(String* key);
        // returns the number of key value pairs in this map
        int size();
        // removes the key value pair in this map
        Object* remove(String* key);
        // clears the map
        void clear();
        // creates a clone of this map
        Map* clone();
        // returns an array of copied keys in map, not sorted
        // call size to determine the number String*
        String** get_keys();
};