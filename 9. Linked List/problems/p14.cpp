// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1/?track=PC-W5-LL&batchId=154
Node* detectLoop(Node* head){
    Node *ptr, *fastPtr;
    ptr = head;
    fastPtr = head;
    ptr = ptr->next;

    if(fastPtr->next!=NULL)
        fastPtr = fastPtr->next->next;
    else
        fastPtr = NULL;

    while(fastPtr!=NULL){
        if(ptr==fastPtr)
            return ptr;
        
        ptr = ptr->next;
        if(fastPtr->next!=NULL)
            fastPtr = fastPtr->next->next;
        else
            fastPtr = NULL;
    }

    return NULL;
}

int countNodesinLoop(struct Node *head){
    Node* temp = detectLoop(head);
    if(temp==NULL)
        return 0;
    int count = 1;
    Node* node = temp->next;
    while(node!=temp){
        node = node->next;
        count++;
    }
    return count;
}
