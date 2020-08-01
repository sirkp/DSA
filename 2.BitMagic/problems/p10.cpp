// https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1/?track=SPCF-BitMagic&batchId=154
unsigned int swapBits(unsigned int n){
	int d = ((int)log2(n)+1);
    if(d%2==1)
        d++;
    unsigned int no = 0;    
    int div, d1, d2;
    for(int i=(d-1);i>=1;i-=2){
        div = (1<<i);
        d1 = (n/div)%2;
        d2 = ((n/(div/2)))%2;
        if(d2)
            no += div;
        if(d1)
            no += (div/2);
    } 
    return no;   
}