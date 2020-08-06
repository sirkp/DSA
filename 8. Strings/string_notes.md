# String
 Strings are defined as a stream of characters.

## String using char array(terminated with '\0')
 1. char str[] = "GeeksforGeeks";

 2. char str[50] = "GeeksforGeeks";

 3. char str[] = {'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'};

 4. char str[14] = {'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'}; 

### passing char array string
 ```C++
 printStr(str);
 void printStr(char str[]) 
 { 
        printf("String is : %s",str); 
 }
 ```

## string Class vs Character array:
String class | Character array       
------------ | --------------- 
dynamic memory allocation | static memory allocation
array of chars terminated by null | it is object which represent stream of chars
