// https://practice.geeksforgeeks.org/problems/rotate-deque-by-k/1/?track=DSASP-Deque&batchId=154
void left_Rotate_Deq_ByK(deque<int> &dq, int n, int k){
    for(int i=0;i<k;i++){
        int temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
    }
    
}

void right_Rotate_Deq_ByK(deque<int> &dq, int n, int k){
    for(int i=0;i<k;i++){
        int temp = dq.back();
        dq.pop_back();
        dq.push_front(temp);
    }
}