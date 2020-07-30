// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1/?track=PC-W5-LL&batchId=154
void delNode(Node* prev){// prev is not last node
    Node* nextNode = prev->next;
    prev->next = prev->next->next;
    delete nextNode;
}

Node *removeDuplicates(Node *root){
    Node* node = root;
    Node* prev = node;

    node = node->next;

    while(node!=NULL){
        if(prev->data==node->data){
            node = node->next;
            delNode(prev);
        }else{
            prev = node;
            node = node->next;
        }
    }
    return root;
}
