# Bitwise Magic

- Subtracting 1 from a decimal number flips all the bits after the rightmost set bit including rightmost bit. Eg- 10 = 1010
          9 = 1001
- In 2's complement, all bits are reverted except the first '1' from right to left. Eg- 12 = 1100
    2's = 0111                  

## Left shift operator 
    x << y = x*2^y
    Eg- 3 << 1 = 6

## Right shift operator 
    x >> y = floor(x/2^y)
    Eg- 33 >> 2 = 8
    32 representation
    2  - 000...10
    -2 - 100...10

## Not operator
    signed numbers are stored as 2's complement
    32 representation
    ~x = 2^32 - 1 - x
    2's complement representation = ((2^32 - 1) - (2^32 - 1 - x) + 1)
                                  = -(x+1)  // sign comes due to inversion

    1's complement of x = -(x+1)
    2's complement of x = -x
    Explanation:
    2's complement of x = 2^32 - x
    2's complement representation = 2^32 - (2^32-x)
                                = -x // sign comes due to inversion                            


- 1's complement of x = -(x+1)
- 2's complement of x = -x