// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1/?track=SPC-Stack&batchId=154
vector <long long> prevNoOfLargerElement(long long arr[], int n){
    vector<long long> v(n, 1);
    int prev = 0;
    for(int i=1;i<n;i++){
        prev = i-1;
        while(prev>=0 && arr[i]<=arr[prev]){
            v[i] += v[prev];
            prev -= v[prev];
        }
    }
    return v;
}

vector <long long> nextNoOfLargerElement(long long arr[], int n){
    vector<long long> v(n, 1);
    int prev;
    for(int i=(n-1);i>=0;i--){
        prev = i+1;
        while(prev<n && arr[i]<=arr[prev]){
            v[i] += v[prev];
            prev += v[prev];
        }
    }
    for(int i=0;i<n;i++){
        v[i]--;
    }
    return v;
}

long getMaxArea(long long arr[], int n){
    long maxArea = -1;
    vector<long long> prev = prevNoOfLargerElement(arr, n);
    vector<long long> next = nextNoOfLargerElement(arr, n);
    for(int i=0;i<n;i++){
        prev[i] += next[i];
        maxArea = max(maxArea, (long)(prev[i]*arr[i]));
    }
    return maxArea;
}
