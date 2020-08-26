// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/?track=DSASP-Tree&batchId=154
int util(Node* node, int &ans){
    if(node!=NULL){
        int l = util(node->left, ans);
        int r = util(node->right, ans);

        int m = max(node->data+l, node->data+r);
        m = max(m, node->data);
        ans = max(ans, m);
        ans = max(ans, node->data+l+r);
        return m;
    }else
        return 0;
}

int findMaxSum(Node* root){
    int ans = INT_MIN;
    int temp = util(root, ans);
    return ans;
}