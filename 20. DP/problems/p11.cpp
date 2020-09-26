// https://practice.geeksforgeeks.org/problems/reach-a-given-score1418/1/?track=DSASP-DP&batchId=154
ll count(ll n){
    vector<int> digits{3, 5, 10};
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(auto no: digits){
        for(int i=1;i<=n;i++){
            if(i>=no)
                dp[i] += dp[i-no];
        }
    }
    return dp[n];
}