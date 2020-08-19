// https://practice.geeksforgeeks.org/problems/fibonacci-numbers-bottom-up-dp/1/?track=DSASP-DP&batchId=154
long long findNthFibonacci(int number){
    long long a = 1;
    long long b = 1;
    int i=2;
    while(i<number){
        long long t = a+b;
        a = b;
        b = t;
        i++;
    }
    return b;
    
}