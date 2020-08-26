// https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1
void util(Node* node, int low, int high, vector<int> &v){
    if(node){
        if(low<node->data)
            util(node->left, low, high, v);

        if(node->data>=low && node->data<=high)
            v.push_back(node->data);
        
        if(high>=node->data)
            util(node->right, low, high, v);
    }
}

vector<int> printNearNodes(Node *root, int low, int high){
    vector<int> v;
    util(root, low, high, v);
    return v;
}
