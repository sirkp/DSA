// https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/1/?track=DSASP-Heap&batchId=154
int kthSmallest(int arr[], int n, int k){// nlogk
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

// klogk
void heapify(int p, int arr[], int n){
    int s = p;
    int lc = 2*p+1;
    int rc = 2*p+2;

    if(lc<n && arr[lc]<arr[s])
        s = lc;
    if(rc<n && arr[rc]<arr[s])
        s = rc;
    
    if(s!=p){
        swap(arr[s], arr[p]);
        heapify(s, arr, n);
    }
}

int kthSmallest(int arr[],int n, int k){
    for(int i=((n/2)-1);i>=0;i--)
        heapify(i, arr, n);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(arr[0], 0));

    for(int i=0;i<(k-1);i++){
        int p = pq.top().second;
        pq.pop();
        int l = (2*p)+1;
        int r = (2*p)+2;

        if(l<n)
            pq.push(make_pair(arr[l], l));
        if(r<n)
            pq.push(make_pair(arr[r], r));
    }

    return pq.top().first;
}
