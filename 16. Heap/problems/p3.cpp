// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1/?track=DSASP-Heap&batchId=154
vector<int> kLargest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    
    for(int i=k;i<n;i++)
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    
    vector<int> v;
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    return v;
}