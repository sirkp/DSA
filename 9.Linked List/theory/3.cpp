// insertion at begining
// insertion after key

Node* insertAtBegin(Node* head, int data){
    Node* node = new Node(data);
    node->next = head;
    return node;
}

Node* getNodeWithKey(Node* head, int key){
    while(head!=NULL && head->data!=key){
        head =head->next;
    }
    return head;
}

void insertAfterKey(Node* head, int data, int key){
    Node* node = new Node(data);
    Node* prevNode = getNodeWithKey(head, key);
    if(prevNode!=NULL){
        node->next = prevNode->next;
        prevNode->next = node;
    }
}

void test(){
    // insertion at begining
    Node* head = NULL;
    head = insertAtBegin(head,1);
    head = insertAtBegin(head,2);
    head = insertAtBegin(head,3);
    head = insertAtBegin(head,4);
    displayLinkedList(head);

    // insertion after key
    insertAfterKey(head, 5, 4); 
    insertAfterKey(head, 6, 3); 
    insertAfterKey(head, 7, 2); 
    insertAfterKey(head, 8, 1); 
    insertAfterKey(head, 9, 0); 
    displayLinkedList(head);
}
