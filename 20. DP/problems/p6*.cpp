// https://practice.geeksforgeeks.org/problems/coin-change-number-of-ways/1/?track=DSASP-DP&batchId=154
long long numberOfWays(int coins[],int n,int value){
    vector<long long> dp(value+1, 0);
    dp[0] = 1;

    for(int i=0;i<n;i++){
        for(int val=1;val<=value;val++){
            if(val>=coins[i]){
                dp[val] += dp[val-coins[i]];
            }
        }
    }
    return dp[value];
}
