// https://practice.geeksforgeeks.org/problems/fibonacci-numbers-bottom-up-dp/1/?track=DSASP-DP&batchId=154

// fiboncii no in log(n)
*****
n->odd: k = (n+1)/2 f(n) = f(k)*f(k) + f(k-1)*f(k-1)
n->even: k = n/2 f(n) = f(k)*f(k) + 2*f(k-1)*f(k)
*****

long long util(int n, long long dp[]){
    if(n==0)
        return n;
    else if(dp[n])
        return dp[n];

    int k = (n&1)?(n+1)/2:n/2;

    dp[n] = (n&1)?((util(k, dp)*util(k, dp))+(util(k-1, dp)*util(k-1, dp))):((util(k, dp)*util(k, dp))+(2*util(k-1, dp)*util(k, dp))); 
    return dp[n];
}

long long findNthFibonacci(int n){
    long long dp[n+1] = {0};
    return util(n, dp);

}