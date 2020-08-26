// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/?track=DSASP-Tree&batchId=154
int util(Node* node, int x, int &ans){
    if(node!=NULL){
        int l = util(node->left, x, ans);
        int r = util(node->right, x, ans);
        
        if((l+r+node->data)==x)
            ans++;

        return (l+r+node->data);
    }else
        return 0;
}

int countSubtreesWithSumX(Node* root, int x){
	int ans = 0;
    int temp = util(root, x, ans);
    return ans;
}