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


// Augmented BST approach

class Node{
public:
    int data;
    int leftCount;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        leftCount = 0;
    }
};

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
            node->leftCount--;
        }else{
            Node* r = deleteNode(node->right, x);
            node->right = r;
        }
        return node;
    }else
        return NULL;
}

int kthElement(Node* node, int k, int prev=0){ // method1 passing prev values
    if(node){
        if(k==(prev+node->leftCount+1)){
            return node->data;
        }else if(k<(prev+node->leftCount+1)){
            return kthElement(node->left, k, prev);
        }else{
            return kthElement(node->right, k, (prev+node->leftCount+1));
        }
    }else
        return -1;

}

int kthElement(Node* node, int k){ // method2 subtracting k
    if(node){
        if(k==(node->leftCount+1)){
            return node->data;
        }else if(k<(node->leftCount+1)){
            return kthElement(node->left, k);
        }else{
            return kthElement(node->right, (k-(node->leftCount+1)));
        }
    }else
        return -1;
}