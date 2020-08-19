// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1/?track=DSASP-Tree&batchId=154
Node *createTree(int parent[], int n){
    Node* arr[n];
    for(int i=0;i<n;i++)
        arr[i] = new Node(i);
    
    int pos;
    
    for(int i=0;i<n;i++){
        if(parent[i]==-1)
            pos = i;
        else{
            if(arr[parent[i]]->left==NULL)
                arr[parent[i]]->left = arr[i];
            else
                arr[parent[i]]->right = arr[i];
        }
    }
    return arr[pos];
    
}