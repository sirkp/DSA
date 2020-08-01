// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1/?track=PC-W5-LL&batchId=154
int getCount(struct Node* head){
    int c = 0;
    while(head!=NULL){
        c++;
        head = head->next;
    }
    return c;
}

Node* reverseList(Node *head){
    Node *node = head, *prev = NULL, *nextNode = NULL;

    while(node!=NULL){
        nextNode = node->next;
        node->next = prev;
        prev = node;
        node = nextNode;
    }
    head = prev;
    return head;
}

bool isPalindrome(Node *head){
    int n = getCount(head);
    Node *node1 = head;
    int c = 0;
    while(c<(((n+1)/2)-1)){
        c++;
        node1 = node1->next;
    }
    node1->next = reverseList(node1->next);

    Node* node2 = node1->next;
    node1 = head;

    c = 0;
    while(c<=(((n+1)/2)-1)){
        if(!(node2 == NULL ||node1->data==node2->data))
            return false;
        c++;
        node1 = node1->next;
        
        if(node2!=NULL)
            node2 = node2->next;
    }
    return true;
}
