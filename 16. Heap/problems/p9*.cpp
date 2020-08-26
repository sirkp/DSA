// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1/
vector <int> nearlySorted(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<=k&&i<n;i++)
        pq.push(arr[i]);
    
    vector<int> v;
    for(int i=(k+1);i<n;i++){
        v.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}