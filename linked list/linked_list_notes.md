# Linked List

## Singly Linked List
 Linked Lists are linear or sequential data structures in which elements are stored at non-contiguous memory location and are linked to each other using pointers. 
 
 Each element consist of two parts:
 1. data
 2. pointer

### Advantages over array
 1. linked list has no fixed size unlikely array.
 2. insertion and deletion are less costly as compared to array.

### Disadvantages
 1. Random access is not allowed
 2. extra space for pointer.
 3. not cache friendly as elements are stored at non contigous location.

## Doubly Linked List
 Doubly Linked Lists are also a sequential data structure with the only difference that the doubly linked lists contain two pointers instead of one to store the address of both next node and previous node respectively.

### Advantages:
 1. can traverse backward
 2. quickly delete a node if its ptr is given without traversing LL.
 3. quickly insert a node before a node if its ptr is given without traversing LL.
 
### Disadvantages:
 1. extra space for prev ptr.
 2. an extra ptr is need to be maintained in insertion and deletion operator