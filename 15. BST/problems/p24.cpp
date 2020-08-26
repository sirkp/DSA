// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1/
void util(Node* node, Node* &prev, Node* &a, Node* &b){
    if(node){
        util(node->left, prev, a, b);
        
        if(prev && a==NULL && node->data<=prev->data)
                a = prev;

        if(a){
            if(!b)
                b = node;
            else if(node->data<b->data)
                b = node;
        }

        prev = node;

        util(node->right, prev, a, b);
    }
}

Node *correctBST(Node* root ){
    Node* prev = NULL;
    Node* a = NULL;
    Node* b = NULL;

    util(root, prev, a, b);
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    return root;
}
