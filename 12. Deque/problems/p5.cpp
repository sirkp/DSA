// https://practice.geeksforgeeks.org/problems/insertion-in-deque/1/?track=DSASP-Deque&batchId=154
deque<int> deque_Init(int arr[], int n){
    deque<int> dq;
    for(int i=0;i<n;i++)
        dq.push_back(arr[i]);
    return dq;
}