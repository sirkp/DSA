// https://practice.geeksforgeeks.org/problems/mirror-tree/1/?track=PC-W6-T&batchId=154
void mirror(Node* node) {
    if(node!=NULL){
        Node* temp;
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirror(node->right);
        mirror(node->left);
    }
}