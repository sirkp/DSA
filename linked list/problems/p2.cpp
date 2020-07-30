// https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1/?track=PC-W5-LL&batchId=154
Node *insertAtBegining(Node *head, int data) {
    Node* node = new Node(data);
    node->next = head;
    return node;
}

Node* getLastNode(Node* head){
    if(head==NULL)
        return NULL;
    while(head->next!=NULL){
        head = head->next;
    }
    return head;
}


// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int data)  {
   // Your code here
   Node* node = new Node(data);

    if(head == NULL)
        return node;
    else{
        Node* last = getLastNode(head);
        last->next = node;
        return head;
    }    
}
