// https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/1/?track=DSASP-Heap&batchId=154
int kthSmallest(int arr[], int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);

    for(int i=k;i<n;i++)
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    return pq.top();
}