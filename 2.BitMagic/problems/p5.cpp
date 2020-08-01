// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1/?track=SPCF-BitMagic&batchId=154
int countBitsFlip(int a, int b){
    
    int count = 0;
    while(a!=0 || b!=0){
        if((a%2)!=(b%2))
            count++;
        a = a/2;
        b = b/2;
    }
    return count;
    
}