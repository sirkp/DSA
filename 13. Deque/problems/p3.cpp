// https://practice.geeksforgeeks.org/problems/dequeue-traversal/1/?track=DSASP-Deque&batchId=154
void printDeque(deque<int> dq){
    int n = (int)dq.size();
    for(int i=0;i<n;i++){
        int temp = dq.front();
        cout<<temp<<" ";
        dq.pop_front();
        dq.push_back(temp);
    }
}    