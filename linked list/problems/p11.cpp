// https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1/?track=PC-W5-LL&batchId=154
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

void getNthNodes(Node* head, int k, Node** prev1, Node** prev2){
    int count = 0;
    Node* node = head;
    Node* prev = NULL;
    while(count<(k-1) && node!=NULL){
        count++;
        prev = node;
        node = node->next;    
    }

    (*prev1) = prev;
    count++;
    node = node->next;

    Node* newNode = head;
    prev = NULL;

    while(node!=NULL){
        prev = newNode;
        node = node->next;
        newNode = newNode->next;
        count++;
    }
    // if(k>count) not possible
    (*prev2) = prev;

}

Node* swapkthnode(Node* head, int n, int k){
    if(k>n)
        return head;

    Node *prev1=NULL, *prev2=NULL;

    getNthNodes(head, k, &prev1, &prev2);
    head = swapNodes(head, prev1, prev2);
    return head;    
}
 