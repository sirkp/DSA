// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1/?track=SPCF-BitMagic&batchId=154
unsigned int getFirstSetBitOptimised(int n){
	if(n==0)
	return 0;
	n = (n & -n);// 2's complement of x is -x
	return (log2(n) + 1); 
}

unsigned int getFirstSetBit(int n){
    
    // Your code here
    unsigned int count = 0; 
    
    while(n!=0){
        if(n%2==1)
        return (count+1);
        n /= 2;
        count++;
    }
    return 0;
    
}
