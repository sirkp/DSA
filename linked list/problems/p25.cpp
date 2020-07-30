// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1/?track=PC-W5-LL&batchId=154

// Method 1 time: O(n), space: O(n)
Node *copyList(Node *head) {
    Node* node = head, *copy;
    unordered_map<Node*, Node*> hash;
    while(node!=NULL){
        hash[node] = new Node(node->data);
        node = node->next;
    }
    
    node = head;
    while(node!=NULL){
        copy = hash[node];
        copy->next = hash[node->next];
        copy->arb = hash[node->arb];
        node = node->next;
    }
    return hash[head];
}

// Method 2 time: O(n), space: O(1)

void insertNodeNextToItself(Node* head){
    Node *node = head, *nextNode = NULL;
    while(node!=NULL){
        nextNode = node->next;
        node->next = new Node(node->data);
        node->next->next = nextNode;
        node = nextNode;
    }
}

void setRandomPtr(Node* head){
    Node *node = head;
    while(node!=NULL){
        node->next->arb = node->arb==NULL?NULL:node->arb->next;
        node = node->next->next;
    }
}

Node* separateLists(Node* head){
    Node *org = head, *copy = head->next, *copyHead = head->next;
    while(copy->next!=NULL){
        org->next = org->next->next;
        copy->next = copy->next->next;
        org = org->next;
        copy = copy->next;
    } 
    org->next = NULL;
    return copyHead;
}

Node *copyList(Node *head) {
    Node *node = head, *nextNode = NULL, *temp;
    insertNodeNextToItself(head);
    setRandomPtr(head);
    return separateLists(head);
}
