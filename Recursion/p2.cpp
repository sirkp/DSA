// https://practice.geeksforgeeks.org/problems/sum-of-digits-of-a-number/1/?track=SPCF-Recursion&batchId=154
int sumOfDigits(int n)
{
    //Your code here
    if(n==0)
    return 0;
    
    return (n%10 + sumOfDigits(n/10));
}