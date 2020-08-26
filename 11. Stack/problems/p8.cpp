// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1/?track=SPC-Stack&batchId=154
void QueueStack :: push(int x){
    if(q1.empty()){
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }else{
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }
}

int QueueStack :: pop(){
    if(!q1.empty()){
        int temp = q1.front();
        q1.pop();
        return temp;
    } else if(!q2.empty()){
        int temp = q2.front();
        q2.pop();
        return temp;
    } else
        return -1;
}
