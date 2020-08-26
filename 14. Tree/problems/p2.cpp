// https://practice.geeksforgeeks.org/problems/inorder-traversal/1/?track=PC-W6-T&batchId=154
void inorderUtil(Node* root, vector<int>& v){
    if(root!=NULL){
        inorderUtil(root->left, v);
        v.push_back(root->data);
        inorderUtil(root->right, v);
    }
}

vector<int> inOrder(Node* root){
    vector<int> v;
    inorderUtil(root, v);
    return v;
}