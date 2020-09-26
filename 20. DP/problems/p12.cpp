// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps4102/1/?track=DSASP-DP&batchId=154
int minimumJumps(int arr[], int n){
    if(arr[0]==0)
        return -1;

    vector<int> dp(n, -1);
    dp[0] = 0;

    int j = 1;
    for(int i=0;i<n;i++){
        if(j>=n || i>j)
            break;
        if((i+1)<=j){
            int maxInd = min(i+arr[i], n-1);
            while(j<=maxInd){
                    dp[j] = dp[i]+1;
                j++;
            }
        }
    }
    return dp[n-1];
}