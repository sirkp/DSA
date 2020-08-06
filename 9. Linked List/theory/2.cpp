// insertion at end

void displayLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


Node* getLastNode(Node* head){
    if(head==NULL)
        return NULL;
    while(head->next!=NULL){
        head = head->next;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data){
    Node* node = new Node(data);

    if(head == NULL)
        return node;
    else{
        Node* last = getLastNode(head);
        last->next = node;
        return head;
    }    
}

void test(){
    // insertion
    Node* head = NULL;
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    displayLinkedList(head);
}
