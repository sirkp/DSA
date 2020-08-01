// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1/?track=SPC-Queue&batchId=154
void StackQueue :: push(int x){
    s1.push(x); 
}

int StackQueue :: pop(){
    if(!s1.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }else
        return -1;
}
