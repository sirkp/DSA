// swape nodes
Node* swapNodes(Node* head, Node* prev1, Node* prev2){// NULL denotes node is head
    if(prev1 == prev2)                                // both prev1 prev2 can't be null
        return head;
    // intialising node1, node2 
    Node *node1 = NULL, *node2 = NULL ; 
    if(prev1==NULL)
        node1 = head;
    else
        node1 = prev1->next;

    if(prev2==NULL)
        node2 = head;
    else
        node2 = prev2->next;    

    Node *temp = node2->next; 


    // algo
    if(prev1==NULL)
        head = node2;
    else
        prev1->next = node2;

    if(prev2==NULL)
        head = node1;
    else
        prev2->next = node1;

    node2->next = node1->next;

    node1->next = temp;

    return head;
}
