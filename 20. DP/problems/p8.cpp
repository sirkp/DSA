// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1/
#define MOD 1000000007

long long countWays(int m){
    vector<long long> dp(m+1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=m;i++){
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
    return dp[m];
}