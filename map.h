//lang:CwC
#include "object.h"

// Represents a Map object of Objects to Objects
// owns the values and does copy on puts (both key and value)
class Map : public Object {
    public:
        // default constructor
        Map(){}
        // copy constructor
        Map(Map* m){}
        // default destructor
        ~Map(){}

        // is this map equal to the object
        bool equals(Object *o);
        // associates the value with the key in this map
        void put(Object *key, Object *value);
        // returns the value associated this key in the map
        Object* get(Object* key);
        // checks if the map contains a value with this key
        bool contains(Object* key);
        // returns the number of key value pairs in this map
        int size();
        // removes the key value pair in this map
        Object* remove(Object* key);
        // clears the map
        void clear();
        // creates a clone of this map
        Map* clone();
        // returns an array of copied keys in map, not sorted
        // call size to determine the number String*
        Object** get_keys();
};