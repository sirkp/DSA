// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
int util(Node* node, int &i, int k){
    if(node){
        int l = util(node->left, i, k);

        if(l!=-1)
            return l;

        if(i==k){
            return node->data;
        }
        i++;

        int r = util(node->right, i, k);
        return r;

    }else
        return -1;
}

int KthSmallestElement(Node* node, int k){
    int i = 1;
    return util(node, i, k);
}