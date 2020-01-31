No longer using Jan Vitek's implementation.

The Object class and the String class are taken from https://piazza.com/class/k51bluky59n2jr?cid=345
to attempt to standardize those two objects for everyone in this class. Credits to Chase Bishop.

## Map class

* The map does not owns the values and does not copy on puts (both key and value).
* Maps are a subclass of the Object class.
* Keys are always objects of the Object class and values are all objects of the Object class.
* The map has a default constructor that creates a map with no mappings and a copy constructor that takes in 
an existing map and copies it.
* The map has a put method for putting new mappings of Object to Object or updating existing mappings in the map.
* The map has a get method to get the value associated with a key.
* The map can check if the map contains a value for a key.
* We can remove a mapping from the map.
* The map can tell you its size.
* The map can create a clone of itself.
* The map can provide the user with an array of its keys, not sorted.
