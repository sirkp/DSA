// https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1
long long countWays(int n){
    if(n<=2)
        return n;
    
    vector<long long> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i=4;i<=n;i++){
        dp[i] = (((dp[i-3]+dp[i-2])%MOD)+dp[i-1])%MOD;
    }
    return dp[n];
}
