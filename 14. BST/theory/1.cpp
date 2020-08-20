// search in BST
bool search(Node* root, int x){
    if(root!=NULL){
        if(x==root->data)
            return true;
        else if(x>root->data)
            return search(root->right, x);
        else
            return search(root->left, x);
    }
    return false;
}