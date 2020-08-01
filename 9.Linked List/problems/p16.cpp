// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1/?track=PC-W5-LL&batchId=154
int getCount(Node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

Node* rotate(Node* head, int k){
    int n = getCount(head);
    k = k%n;
    if(k>0){
        Node *node = head, *prev = NULL;
        int c = 0;
        while(node->next!=NULL){
            if(c==(k-1))
                prev = node;
            node = node->next;
            c++;
        }
        node->next = head;
        head = prev->next;
        prev->next = NULL;
    }
    return head;
}
