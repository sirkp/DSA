// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1/?track=PC-W6-T&batchId=154
int height(Node* root, bool& isBalanced){
    if(root!=NULL){
        int l = height(root->left, isBalanced);
        int r = height(root->right, isBalanced);
        if(abs(l-r)>1)
            isBalanced = false;
        return (max(l, r)+1);
    }
    else
        return 0;
}

bool isBalanced(Node *root){
    bool isBalanced = true;
    int temp = height(root, isBalanced);
    return isBalanced;
}