// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/
void util(Node* node, int low, int high, int &ans){
    if(node){
        if(low<node->data)
            util(node->left, low, high, ans);

        if(low<=node->data && node->data<=high)
            ans++;

        if(high>node->data)
            util(node->right, low, high, ans);
    }
}

int getCountOfNode(Node *root, int l, int h){
    int ans = 0;
    util(root, l, h, ans);
    return ans;
}
