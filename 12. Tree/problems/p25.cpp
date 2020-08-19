// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/?track=DSASP-Tree&batchId=154
int getIndex(int arr[], int l, int r, int x){
    for(int i=l;i<=r;i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}

Node* build(int arr[], int l, int r, int post[], int &last){
    if(l<=r){
        int i = getIndex(arr, l, r, post[last--]);
        Node* node = new Node(arr[i]);
        node->right = build(arr, (i+1), r, post, last);
        node->left = build(arr, l, (i-1), post, last);
        return node;
    }else
        return NULL;
}

Node *buildTree(int arr[], int post[], int n) {
    int last = n-1;
    Node* root = build(arr, 0, (n-1), post, last);
    return root;
}