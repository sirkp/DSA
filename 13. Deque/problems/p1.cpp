// https://practice.geeksforgeeks.org/problems/deque-implementations/1/?track=DSASP-Deque&batchId=154
void push_back_pb(deque<int> &dq, int x){
    dq.push_back(x);
}

void pop_back_ppb(deque<int> &dq){
    
    if(!dq.empty())
        dq.pop_back();
    else
        return;
    
}

int front_dq(deque<int> &dq){
    if(!dq.empty())
        return dq.front();
    else
        return -1;
    
}

void push_front_pf(deque<int> &dq, int x){
    dq.push_front(x);
}