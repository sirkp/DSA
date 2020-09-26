// https://practice.geeksforgeeks.org/problems/coin-change-minimum-number-of-coins/1/
long long minimumNumberOfCoins(int coins[],int n,int value){
    vector<long long> dp(value+1, INT_MAX);
    dp[0] = 0;

    for(int i=0;i<n;i++){
        for(int val=1;val<=value;val++){
            if(val>=coins[i]){
                dp[val] = min(dp[val], dp[val-coins[i]]+1);
            }
        }
    }
    if(dp[value]==INT_MAX)
        return -1;
    else
        return dp[value];
}