// https://practice.geeksforgeeks.org/problems/children-sum-parent/1/?track=DSASP-Tree&batchId=154
int util(Node* root){
    if(root!=NULL){
        int l = util(root->left);
        int r = util(root->right);
        if(l==-1 || r==-1)
            return -1;
        else if((l+r)==0 || (l+r)==root->data)
            return root->data;
        else
            return -1;
            
    }else
        return 0;
}

int isSumProperty(Node *root){
    int res = util(root);
    return (res==-1?0:1);
}