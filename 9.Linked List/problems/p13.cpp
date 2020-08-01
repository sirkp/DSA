// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1/?track=PC-W5-LL&batchId=154
bool detectLoop(Node* head){
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
            return true;
        
        ptr = ptr->next;
        if(fastPtr->next!=NULL)
            fastPtr = fastPtr->next->next;
        else
            fastPtr = NULL;
    }

    return false;
}
