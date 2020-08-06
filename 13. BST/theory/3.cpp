// delete a node in BST
Node* getMax(Node* node){
    if(node!=NULL){
        if(node->right==NULL)
            return node;
        else
            return getMax(node->right);
    }else
        return NULL;
}

Node* deleteNode(Node* node,  int x){
    if(node!=NULL){
        if(node->data==x){
            if(node->left==NULL && node->right==NULL){
                delete node;
                node = NULL;
            }
            else if(node->left==NULL || node->right==NULL){
                Node* temp;
                if(node->left!=NULL)
                    temp = node->left;
                else
                    temp = node->right;
                delete node;
                node = temp;
            }else{
                Node* temp = new Node(getMax(node->left)->data);
                node = deleteNode(node, temp->data);
                temp->left = node->left;
                temp->right = node->right;
                delete node;
                node = temp;
            }
        }else if(x<node->data){
            Node* l = deleteNode(node->left, x);
            node->left = l;
        }else{
            Node* r = deleteNode(node->right, x);
            node->right = r;
        }
        return node;
    }else
        return NULL;
}
