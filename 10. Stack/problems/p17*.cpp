// https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/?track=DSASP-Stack&batchId=154
vector<int> nextSmallerElement(int arr[], int n){// without stack
    vector<int> v(n, 1);
    int next;
    for(int i=(n-1);i>=0;i--){
        next = i+1;
        while(next<n && arr[i]<=arr[next]){
            v[i] += v[next];
            next += v[next];
        }
    }
    for(int i=0;i<n;i++){
        v[i] = i+v[i];
    }
    return v;
}

vector<int> prevSmallerElement(int arr[], int n){
    vector<int> v(n, 1);
    int prev;
    for(int i=1;i<n;i++){
        prev = i-1;
        while(arr[i]<=arr[prev] && prev>=0){
            v[i] += v[prev];
            prev -= v[prev];
        }
    }
    for(int i=0;i<n;i++){
        v[i] = i-v[i];
    }
    return v;
}

vector<int> printMaxOfMin(int arr[], int n){
    vector<int> left = prevSmallerElement(arr, n);
    vector<int> right = nextSmallerElement(arr, n);

    vector<int> ans(n+1, 0);
    for(int i=0;i<n;i++)
        ans[right[i]-left[i]-1] = max(ans[right[i]-left[i]-1], arr[i]);

    for(int i=(n-1);i>=1;i--)
        ans[i] = max(ans[i], ans[i+1]);

    ans.erase(ans.begin());
    
    return ans;
}
