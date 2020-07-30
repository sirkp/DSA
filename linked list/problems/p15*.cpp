// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/?track=PC-W5-LL&batchId=154
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

int countNodesinLoop(Node *head){
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

void removeLoop(Node* head){
    int s = countNodesinLoop(head);
    if(s!=0){
        Node* ahead = head;
        int c = 0;
        while(c<s){
            c++;
            ahead = ahead->next;
        }

        Node *start = head;
        while(start!=ahead){
            start = start->next;
            ahead = ahead->next;
        }
        Node* node = start;
        while(node->next!=start)
            node = node->next;

        node->next = NULL;    
    }
}

void removeLoop(Node* head){ // optimised
    int s = countNodesinLoop(head);
    if(s!=0){
        Node* ahead = head;
        int c = 0;
        while(c<(s-1)){
            c++;
            ahead = ahead->next;
        }

        Node *start = NULL;
        while((start==NULL&&ahead->next!=head)  || (start!=NULL && start->next!=ahead->next)){
            if(start==NULL)
                start = head;
            else    
                start = start->next;

            ahead = ahead->next;
        }
        ahead->next = NULL;    
    }
}
