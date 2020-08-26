// https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1/?track=SPC-Stack&batchId=154
void MyStack ::push(int key) {
    StackNode* temp = new StackNode(key);
    temp->next = top;
    top = temp;
}

int MyStack ::pop() {
    if(top!=NULL){
        StackNode* temp = top;
        top = top->next;
        int x = temp->data;
        delete temp;
        return x;
    }
    return -1;
}