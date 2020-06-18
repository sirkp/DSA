// https://practice.geeksforgeeks.org/problems/factorial-of-number/1/?track=SPCF-Mathematics&batchId=154
long long factorial (int N)
{
    //Your code here
    long long f = 1;
    for(int i=2;i<=N;i++)
    f = f * i;
    return f;
}