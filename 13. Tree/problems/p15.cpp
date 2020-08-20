// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/?track=PC-W6-T&batchId=154
int height(Node* root){
    if(root!=NULL)
        return(max(height(root->left), height(root->right))+1);
    else
        return 0;
}

void printRight(Node* root, bool levelArray[], int level){
    if(root!=NULL){
        if(levelArray[level]){
            cout<<root->data<<" ";
            levelArray[level] = false;
        }
        printRight(root->right, levelArray, level+1);
        printRight(root->left, levelArray, level+1);
    }
}

void rightView(Node *root){
    int h = height(root);
    bool levelArray[h];
    for(int i=0;i<h;i++)
        levelArray[i] = true;
    printRight(root, levelArray, 0);
}