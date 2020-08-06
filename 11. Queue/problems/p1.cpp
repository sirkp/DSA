// https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1/?track=SPC-Queue&batchId=154
void MyQueue :: push(int x){
    arr[rear++]=x;
}

int MyQueue :: pop()
{
    if(front!=rear){
        return arr[front++];
    }else  
        return -1;       
}