// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
int distributeChoclate(int arr[], int n, int k){
    k--;
    sort(arr, arr+n);
    int minn = INT_MAX;
    for(int i=0;(i+k)<n;i++){
        minn = min(minn, (arr[(i+k)]-arr[i]));
    }
    return minn;
}