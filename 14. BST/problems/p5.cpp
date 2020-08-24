// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1/
int minValue(Node* root){
    if(root->left==NULL)
        return root->data;
    else
        return minValue(root->left);
}