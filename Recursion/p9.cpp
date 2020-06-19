// https://practice.geeksforgeeks.org/problems/power-using-recursion/1/?track=SPCF-Recursion&batchId=154
int RecursivePower(int n,int p)
{
    if(p==0)
    return 1;
    
    return (n*RecursivePower(n, p-1));
}