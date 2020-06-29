// https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/?track=SPCF-BitMagic&batchId=154
int posOfRightMostDiffBit(int m, int n){
    
    int count = 0;
    while(m!=0 || n!=0){
        if(m%2!=n%2)
            break;
        count++;
        m = m/2;
        n = n/2;
    }
    return (count+1);
    
}