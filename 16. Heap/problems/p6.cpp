// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream-1587115620/1/?track=DSASP-Heap&batchId=154
void kthLargest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<(k-1);i++){
        pq.push(arr[i]);
        cout<<-1<<" ";
    }

    pq.push(arr[k-1]);
    cout<<pq.top()<<" ";

    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
        cout<<pq.top()<<" ";
    }
}