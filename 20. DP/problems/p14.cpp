// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-i/1/?track=DSASP-DP&batchId=154
#define ll long long
ll maximumSum(int arr[], int n){
    long long s = 0;
    ll ans = INT_MIN;
    for(int i=0;i<n;i++){
        long long cn = (long long) arr[i];
        s += cn;
        ans = max(s, ans);
        cout<<s<<" ";
        if(s<0)
            s = 0;
    }
    cout<<endl;
    return ans;
}