// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1/?track=DSASP-Tree&batchId=154
void inorder(Node* node, Node* &prev, Node* &head){
    if(node!=NULL){
        inorder(node->left, prev, head);

        if(prev==NULL)
            head = node;
        else{
            prev->right = node;
            node->left = prev;
        }
        prev = node;

        inorder(node->right, prev, head);
    }
}

Node * bToDLL(Node *node){
    Node* head = NULL;
    Node* prev = NULL;
    inorder(node, prev, head);
    return head;
}