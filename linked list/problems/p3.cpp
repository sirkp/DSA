// https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1/?track=PC-W5-LL&batchId=154
Node* getPthNode(Node* head, int p){
    if(head==NULL)
        return NULL;
    int i = 0;
    while(head!=NULL && i<p){
        head = head->next;
        i++;
    }
    return head;
}

void addNode(Node *head, int pos, int data){
    Node* node = new Node(data);
    Node* last = getPthNode(head, pos);
    if(last!=NULL){
        node->next = last->next;
        last->next = node;
        node->prev = last;
        
        last = node;
        
        node = node->next;
        if(node!=NULL){
            node->prev = last;
        }
    }
}
