// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/?track=DSASP-Deque&batchId=154
vector <int> max_of_subarrays(int *arr, int n, int k){
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[i]>arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    vector<int> v;
    v.push_back(arr[dq.front()]);
    for(int i=k;i<n;i++){
        while(!dq.empty() && dq.front()<=(i-k))
            dq.pop_front();
        
        while(!dq.empty() && arr[i]>arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
        v.push_back(arr[dq.front()]);
    }
    return v;
}