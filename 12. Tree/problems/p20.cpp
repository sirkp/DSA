// https://leetcode.com/problems/longest-univalue-path
int util(Node* node, int& ans){
    if(node!=NULL){
        int l = util(node->left, ans);
        int r = util(node->right, ans);
        
        if(node->left!=NULL && node->right!=NULL && node->data==node->left->data && node->data==node->right->data){
            ans = max(ans, r+l+1);
            if(l>r){
                return (l+1);
            }else{
                return (r+1);
            }
        }else if(node->left!=NULL && node->data==node->left->data){
            l++;
            ans = max(ans, l);
            return l;
        }else if(node->right!=NULL && node->data==node->right->data){
            r++;
            ans = max(ans, r);
            return r;
        }else{
            ans = max(ans, 1);
            return 1;
        }
    }else{
        return -1;
    }
}

int longestUnivaluePath(Node* root) {
    int ans = 1;
    int v = util(root, ans);

    return (ans-1);
}
