// https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1/?track=DSASP-Tree&batchId=154
void mirror(Node* node){
    if(node!=NULL){
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirror(node->left);
        mirror(node->right);
    }
}

bool compare(Node* nodeA, Node* nodeB){
    if(nodeA!=NULL && nodeB!=NULL){
        if((nodeA->left!=NULL && nodeB->left==NULL) || (nodeA->right==NULL && nodeB->right!=NULL))
            return false;

        return (compare(nodeA->left, nodeB->left) && compare(nodeA->right, nodeB->right));
    }else if(nodeA==NULL && nodeB==NULL)
        return true;
    else
        return false;
}

bool IsFoldable(Node* root){
    if(root==NULL)
        return true;
    
    mirror(root->right);
    
    return compare(root->left, root->right);
}
