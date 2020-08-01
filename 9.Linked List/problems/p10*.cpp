// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?track=PC-W5-LL&batchId=154
int getNthFromLast(Node *head, int n){
    int count = 0;
    Node* node = head;

    while(count<n && node!=NULL){
        count++;
        node = node->next;
    }

    Node* newNode = head;
    while(node!=NULL){
        count++;
        node = node->next;
        newNode = newNode->next;
    }
    
    if(n>count)
        return -1;
    else    
        return newNode->data;
}