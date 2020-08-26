// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/?track=SPC-Queue&batchId=154
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k){
    stack<ll> s;
    queue<ll> q2;

    int i=0;
    while(i<k){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!q.empty()){
        q2.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(!q2.empty()){
        q.push(q2.front());
        q2.pop();
    }
    return q;
}
