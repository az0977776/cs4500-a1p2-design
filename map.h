//lang:CwC
#include "object.h"

// Represents a Map object of Objects to Objects
// does not owns the values and does not copy on puts (both key and value)
class Map : public Object {
    public:
        // default constructor
        Map(){}
        // copy constructor
        Map(Map* m){}
        // default destructor
        ~Map(){}

        /* Inherited from Object, generates a hash for a Map */
        size_t hash();
        /* Inherited from Object, checks equality between an Map and an Object */
        bool equals(Object* const obj);
        // associates the value with the key in this map
        void put(Object *key, Object *value);
        // returns the value associated this key in the map
        Object* get(Object* key);
        // checks if the map contains a value with this key
        bool contains(Object* key);
        // returns the number of key value pairs in this map
        int size();
        // removes the key-value pair in this map
        // and returns the value
        Object* remove(Object* key);
        // clears the map
        void clear();
        // creates a clone of this map
        Map* clone();
        // returns an array of copied keys in map, not sorted
        Object** get_keys();
};