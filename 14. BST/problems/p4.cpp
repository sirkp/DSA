// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1/?track=PC-W6-BST&batchId=154
// https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/
bool search(Node* root, int x){
    if(root!=NULL){
        if(x==root->data)
            return true;
        else if(x>root->data)
            return search(root->right, x);
        else
            return search(root->left, x);
    }
    return false;
}