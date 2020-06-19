// https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?track=SPCF-Recursion&batchId=154
long long power(int N,int R)
{
   //Your code here
    if(R==0)
    return 1;
    
    long long p = power(N, R/2)%M;
    if(R%2==0)
    return (((p%M)*(p%M))%M);
    else
    return (((((p%M)*(p%M))%M)*N)%M);
}