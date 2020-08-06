# Hashing
 Direct access table where we make a big array and use key as index in the array. An entry in array is NIL if key is not present.
 
 Hashing is an improvement over Direct Access Table. The idea is to use hash function that converts a given key to a smaller number and uses the small number as index in a table called hash table

 Hashing is useful for:
   - search
   - insert
   - delete

 It is not useful in :
   - finding closest value  (self balancing binary tree is used)
   - sorted data            (self balancing binary tree is used)
   - prefix searching       (trie is used)

 It consists of two components:
 1. **Hash Function:** A function that converts a given big key to a small practical integer value. A good hash function should have following properties:
    - Efficiently computable.
    - Should uniformly distribute the keys (Each table position equally likely for each key)

      Example: 
         - *integers:* **fn()=large_key%m**,a good value of m will be prime number greater than number of key and close to number of key but not close power of 2 and power of 10
         - *strings:* s = "abcd", **fn()**=(s[0]*x^0 + s[1]*x^2 + s[2]*x^3 + s[3]*x^4)%m, x is a number 

 2. **Hash Table:** An array that stores pointers to records corresponding to a given key. An entry in hash table is NIL if no existing key has hash function value equal to the index for the entry.

    *Collision Handling:* Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. Following are the ways to handle collisions:
    - *Chaining:* The idea is to make each cell of hash table point to a linked list of records that have same hash function value. **see notebook notes**
    - *Open Addressing:* In open addressing, all elements are stored in the hash table itself.**see notebook notes**
