// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1/?track=DSASP-DP&batchId=154
cpp_int findCatalan(int no) {
    cpp_int dp[no+1];
    dp[0] = 1;

    for(int n=0;n<no;n++){
        dp[n+1] = 0;
        for(int i=0;i<=n;i++)
            dp[n+1] += dp[i]*dp[n-i];
    }
    return dp[no];
}