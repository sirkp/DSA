int findPartition(int arr[], int n){ 
    int sum = getSum(arr, n)/2;
    
    bool dp[n+1][sum+1]; 
  
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    for (int i=1; i<=n; i++) { 
        for (int j=1; j<=sum; j++) { 
            if (j<arr[i-1])
                dp[i][j] = dp[i-1][j]; 
            else
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
        } 
    }

    for(int i=sum;i>=0;i--)
        if(dp[n][i])
            return abs(getSum(arr, n)-(2*i));
    return 0;
} 
