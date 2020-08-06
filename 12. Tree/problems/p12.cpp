// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1/?track=PC-W6-T&batchId=154
            3
           / \
          5   1
         / \  / \
        6   2 0  8
           / \
          7   4
// this also covers case when n1 = 5 and n2 = 4
Node* lca(Node* root ,int n1 ,int n2 ){
    if(root!=NULL){
        if(root->data==n1 || root->data==n2)
            return root;
        Node* l = lca(root->left, n1, n2);
        Node* r = lca(root->right, n1, n2);
        
        if(l!=NULL&&r!=NULL)
            return root;
        else if(l!=NULL)
            return l;
        else
            return r;
    }
    else
        return NULL;
}