// https://practice.geeksforgeeks.org/problems/digital-root/1/?track=SPCF-Recursion&batchId=154
int sumOfDigits(int n)
{
    if(n==0)
    return 0;
    
    return (n%10 + sumOfDigits(n/10));
}

int digitalRoot(int n)
{
    int sum = sumOfDigits(n);
    if(sum<10)
    return sum;
    else
    return digitalRoot(sum);
}