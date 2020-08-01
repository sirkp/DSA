// https://practice.geeksforgeeks.org/problems/operations-on-queue/1/?track=SPC-Queue&batchId=154
void enqueue(queue<int> &s,int x){
   s.push(x);
}
void dequeue(queue<int> &s){
    if(!s.empty())
        s.pop();
}
int front(queue<int> &s){
    return s.front();
}
string find(queue<int> s, int val){
    bool present = false;
    while(!s.empty()){
        if(s.front()==val){
            present = true;
            break;
        }
        s.pop();
    }
    if(present)
        return "Yes";
    else
        return "No";
}
