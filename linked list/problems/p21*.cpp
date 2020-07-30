// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1/?track=PC-W5-LL&batchId=154

Node* getLastNode(Node* head){
    if(head==NULL)
        return NULL;
    while(head->next!=NULL){
        head = head->next;
    }
    return head;
}

Node* segregate(Node *head){
    Node *zero = NULL, *one = NULL, *two = NULL, *node = head, *nextNode;
    Node *prevZero = NULL, *prevOne = NULL, *prevTwo = NULL;
    while(node!=NULL){
        nextNode = node->next;
        node->next = NULL;
        if(node->data==0){
            if(zero==NULL)
                zero = node;
            else
                prevZero->next = node;    
            prevZero = node;
        }else if(node->data==1){
            if(one==NULL)
                one = node;
            else   
                prevOne->next = node;
            prevOne = node;    
        }else{
            if(two==NULL)
                two = node;
            else   
                prevTwo->next = node;
            prevTwo = node;
        }
        node = nextNode;    
    }
    node = getLastNode(one);
    if(node==NULL)
        one = two;
    else    
        node->next = two;
    
    node = getLastNode(zero);
    if(node==NULL)
        zero = one;
    else
        node->next = one;
    return zero;
}
