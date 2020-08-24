// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1/
void util(Node* node, int x, int &ans){
    if(node){
        ans = min(ans, abs(node->data-x));
        if(x==node->data)
            return;
        else if(x<node->data)
            util(node->left, x, ans);
        else
            util(node->right, x, ans);
    }
}

int minDiff(Node *root, int x){
    int ans = INT_MAX;
    util(root, x, ans);
    return ans;
}