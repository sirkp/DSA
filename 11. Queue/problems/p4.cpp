// https://practice.geeksforgeeks.org/problems/queue-reversal/1/?track=SPC-Queue&batchId=154
queue<long long int> rev(queue<long long int> q){
    stack<long long int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}