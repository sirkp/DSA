// https://practice.geeksforgeeks.org/problems/trapping-rain-water/1/?track=SPCF-Arrays&batchId=155
int trappingWater(int arr[], int n){
    if(n==0)
        return 0;
    int left[n];
    int max = arr[0];
    for(int i=1;i<n;i++){
        left[i] = max;
        if(arr[i]>max)
            max=arr[i];
    }
    
    int right[n];
    max = arr[n-1];
    for(int i=(n-2);i>=0;i--){
        right[i] = max;
        if(arr[i]>max)
            max=arr[i];
    }
    
    int ans = 0;
    int m;
    for(int i=1;i<(n-1);i++){
        m = min(left[i], right[i]);
        if(m>arr[i]){
            ans += (m-arr[i]);
        }
    }
    return ans;
}