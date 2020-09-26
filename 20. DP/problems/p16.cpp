// https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1/?track=DSASP-DP&batchId=154
#define ll long long
#define MOD 1000000007
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int no=2;no<=n;no++){
        for(int i=1;i<=no;i++){
            dp[no] = ((ll)dp[no]+(ll)(((ll)dp[i-1]*(ll)dp[no-i])%MOD))%MOD;
        }
    }
    return dp[n];
}
