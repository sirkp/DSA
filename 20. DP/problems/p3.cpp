// https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1/?track=DSASP-DP&batchId=154
vector<long long> printFibb(int n) {
    vector<long long> dp(n, 1);
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp;
}