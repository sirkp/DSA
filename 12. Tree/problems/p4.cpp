// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/?track=PC-W6-T&batchId=154
int height(Node* root){
    if(root!=NULL)
        return(max(height(root->left), height(root->right))+1);
    else
        return 0;
}