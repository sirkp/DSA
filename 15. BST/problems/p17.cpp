// https://practice.geeksforgeeks.org/tracks/DSASP-BST/
void util(Node* node, Node* &prev, bool &ans){
    if(node!=NULL){
        util(node->left, prev, ans);
        
        if(prev!=NULL && prev->data>=node->data)
            ans = false;
        prev = node;
        
        util(node->right, prev, ans);
    }
}

bool isBST(Node* root) {
    bool ans = true;
    Node* prev = NULL;
    util(root, prev, ans);
    return ans;
}