// https://practice.geeksforgeeks.org/problems/ncr-1587115620/1/?track=DSASP-DP&batchId=154
// c(n, r) = c(n-1, r-1) + c(n-1, r) 
int nCrModp(int n, int r) {
    if(r>n)
        return 0;

    vector<vector<ll>> dp;
    for(int i=0;i<=n;i++){
        vector<ll> temp(min(i+1, r+1), 0);
        dp.push_back(temp);
    }

    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(int i=0;i<=n;i++)
        if(i==((int)dp[i].size()-1))
            dp[i][i]=1;
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<(int)dp[i].size();j++){
            if(dp[i][j]==0){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                dp[i][j] = dp[i][j]%MOD;
            }
        }
    }
    return dp[n][r];
} 
