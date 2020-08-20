// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/?track=PC-W6-T&batchId=154
int height(Node* root){
    if(root!=NULL)
        return(max(height(root->left), height(root->right))+1);
    else
        return 0;
}

void printLeft(Node* root, bool levelArray[], int level){
    if(root!=NULL){
        if(levelArray[level]){
            cout<<root->data<<" ";
            levelArray[level] = false;
        }
        printLeft(root->left, levelArray, level+1);
        printLeft(root->right, levelArray, level+1);
    }
}

void leftView(Node *root){
    int h = height(root);
    bool levelArray[h];
    for(int i=0;i<h;i++)
        levelArray[i] = true;
    printLeft(root, levelArray, 0);
}
