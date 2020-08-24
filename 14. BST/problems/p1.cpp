// https://practice.geeksforgeeks.org/problems/inorder-traversal-of-a-bst/1/
void util(Node* node, vector<int> &v){
    if(node!=NULL){
        util(node->left, v);
        v.push_back(node->data);
        util(node->right, v);
    }
}

vector <int> inOrder(Node *node) {
    vector<int> v;
    util(node, v);
    return v;
}


// iterative method
vector<int> inOrder(Node* node){
    vector<int> v;
    stack<Node*> s;

    while(node!=NULL || !s.empty()){
        if(node){
            s.push(node);
            node = node->left;
        }else{
            v.push_back(s.top()->data);
            node = s.top()->right;
            s.pop();
        }
    }
    return v;
}
