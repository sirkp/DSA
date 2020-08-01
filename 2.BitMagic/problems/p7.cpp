// https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1/?track=SPCF-BitMagic&batchId=154
int maxConsecutiveOnes(int n)
{
 
    int maxx = 0;
    int c = 0;
    
    while(n!=0){
        if(n%2)
            c++;
        else{
            if(c>maxx)
                maxx = c;
            c = 0;    
        }
        n = n/2;
    }
    if(c>maxx)
        maxx = c;
    return maxx;
}
