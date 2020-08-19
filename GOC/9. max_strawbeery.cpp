int util(int arr[], int k, int available, vector<vector<int>> dp){
    if(k < 0)
        return 0;
        
    if(dp[k][available] == -1) {
        int notSelected = util(arr, k - 1, available, dp);
        int selected = available - arr[k] < 0 ? 0 : arr[k] + util(arr, k - 2, available - arr[k], dp);
        dp[k][available] = max(notSelected, selected);
    }
    return dp[k][available];
}

int maxStrawberry1(int arr[], int n, int sum){
    vector<vector<int>> dp;
    vector<int> temp;
    
    for(int j=0;j<=sum;j++)
        temp.push_back(-1);
    for(int i=0;i<n;i++)
        dp.push_back(temp);

    int ans = util(arr, n-1, sum, dp);
    return (ans == -1 ? 0 : ans);
}

int maxStrawberry2(int arr[], int n, int sum){
    set<int> f,g;
    f.insert(0);
    g.insert(0);
    
    for(int i=0;i<n;i++){
        set<int> f_new, g_new;
        
        for(auto x: g){
            f_new.insert(x);
            if(x+arr[i]<=sum)
                f_new.insert(x+arr[i]);
        }

        g_new = g;
        for(auto x: f)
            g_new.insert(x);

        f = f_new;
        g = g_new;
    }
    int ans = -1;
    for(auto x: g)
        ans = max(ans, x);

    for(auto x: f)
        ans = max(ans, x);
    return ans;
}
