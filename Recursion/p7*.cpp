// https://practice.geeksforgeeks.org/problems/josephus-problem/1/?track=SPCF-Recursion&batchId=154
int j(int n, int k){
    if(n==0)
    return 0;
    
    return (j(n-1, k)+k)%n;
}

int josephus(int n, int k)
{
   return j(n, k) + 1;
}