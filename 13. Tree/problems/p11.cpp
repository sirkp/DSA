// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/?track=PC-W6-T&batchId=154
int height(Node* root, int& diameter){
    if(root!=NULL){
        int l = height(root->left, diameter);
        int r = height(root->right, diameter);
        diameter = max(diameter, l+r+1);
        return (max(l, r)+1);
    }
    else
        return 0;
}

int diameter(Node* node) {
    int diameter = -1;
    int temp = height(node, diameter);
    return diameter;
}