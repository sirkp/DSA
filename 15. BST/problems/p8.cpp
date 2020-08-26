// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1/?track=DSASP-BST&batchId=154
Node* LCA(Node* node, int n1, int n2){
    if(node){
        if(node->data==n1 || node->data==n2)
            return node;
        
        Node* l = LCA(node->left, n1, n2);
        Node* r = LCA(node->right, n1, n2);

        if(l!=NULL && r!=NULL)
            return node;
        else if(l)
            return l;
        else if(r)
            return r;
        else
            return NULL;
    }else
        return NULL;
}
