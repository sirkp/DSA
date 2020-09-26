// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-ii/1/?track=DSASP-DP&batchId=154
int getMax(int arr[], int n){
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
        ans = max(ans, arr[i]);
    return ans;
}

int getFirstPosIndex(int arr[], int n){
    for(int i=0;i<n;i++)
        if(arr[i]>0)
            return i;
    return n;
}

long long maximumSum(int arr[], int n){
    int j = getFirstPosIndex(arr, n);
    if(j==n)
        return getMax(arr, n);

    int inc = arr[j], notInc = 0;
    int prev = j;
    ll e;
    for(int i=(j+1);i<n;i++){
        e = arr[i];
        if(e>0){
            int prevInc = inc;
            if((i-prev)==1){
                inc = notInc+e;
                notInc = max(prevInc, notInc);
            }else{
                inc = max(inc, notInc)+e;
                notInc = max(prevInc, notInc);
            }
            prev = i;
        }
    }
    return max(inc, notInc);
}
