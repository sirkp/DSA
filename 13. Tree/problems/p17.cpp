// https://practice.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1/?track=DSASP-Tree&amp;batchId=154
void util(Node* node, int n, int& low, int& high){
    if(node!=NULL){
        util(node->left, n-1, low, high);
        util(node->right, n+1, low, high);
    }else{
        low = min(low, n+1);
        high = max(high, n-1);
    }
}

int verticalWidth(Node* root){
    int low = 0, high = 0;
    util(root, 0, low, high);
    int ans = high - low;
    if(root!=NULL)
        ans++;
    return ans;
}