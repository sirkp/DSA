// https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1/?track=PC-W6-BST&batchId=154
Node* insert(Node* root, int key){
    if(root!=NULL){
        if(root->data==key)
            return root;
        else if(key>root->data){
            Node* right = insert(root->right, key);
            root->right = right;
        }
        else{
            Node* left = insert(root->left, key);
            root->left = left;
        }
        return root;
    }else  
        return new Node(key);
}
