// https://practice.geeksforgeeks.org/problems/preorder-traversal/1/?track=PC-W6-T&batchId=154
// CLR
void preorderUtil(Node* root, vector<int>& v){
    if(root!=NULL){
        v.push_back(root->data);
        preorderUtil(root->left, v);
        preorderUtil(root->right, v);
    }
}

vector <int> preorder(Node* root){
    vector<int> v;
    preorderUtil(root, v);
    return v;
}
