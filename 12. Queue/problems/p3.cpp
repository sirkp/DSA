// https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1/?track=SPC-Queue&batchId=154
void MyQueue:: push(int x){
    if(rear==NULL){
        rear = new QueueNode(x);
        front = rear;
    }else{
        rear->next = new QueueNode(x);
        rear = rear->next;
    }
}

int MyQueue :: pop(){
    if(rear!=NULL){
        if(rear==front){
            int temp = front->data;
            front = NULL;
            rear = NULL;
            return temp;
        }else{
            QueueNode* temp = front;
            front = front->next;
            int tempData = temp->data;
            temp = NULL;
            return tempData;
        }   
    }else
        return -1;
}
