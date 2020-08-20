// https://practice.geeksforgeeks.org/problems/postorder-traversal/1/?track=PC-W6-T&batchId=154
void postOrderUtil(Node* root, vector<int>& v){
    if(root!=NULL){
        postOrderUtil(root->left, v);
        postOrderUtil(root->right, v);
        v.push_back(root->data);
    }
}

vector<int> postOrder(Node* root){
    vector<int> v;
    postOrderUtil(root, v);
    return v;
}
