// https://practice.geeksforgeeks.org/problems/mean-and-median-1587115620/1/?track=SPCF-Arrays&batchId=154
int median(int A[],int N)
{
    sort(A,A+N);
    if(N%2==1)
    return A[N/2];
    else{
        int i = N/2;
        return ((A[i]+A[i-1])/2);
    }
}

int mean(int A[],int N)
{
    int sum = 0;
    
    for(int i=0;i<N;i++)
    sum += A[i];
    
    return (sum/N);
}