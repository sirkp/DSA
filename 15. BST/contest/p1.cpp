// https://practice.geeksforgeeks.org/contest-problem/alternate-leaf-nodes-summ4246543604281248/0/
Node* insert(Node* node, int key){
    if(node){
        if(node->data==key)
            return node;
        else if(key<node->data){
            Node* l = insert(node->left, key);
            node->left = l;
        }else{
            Node* r = insert(node->right, key);
            node->right = r;
        }
        return node;
    }else{
        return new Node(key);
    }
}

void getLeafSum(Node* node, bool &isPrev, int &ans){
    if(node){
        if(node->left==NULL && node->right==NULL){
            if(!isPrev){
                ans += node->data;
            }
            isPrev = !isPrev;
        }
        getLeafSum(node->left, isPrev, ans);
        getLeafSum(node->right, isPrev, ans);
    }
}

int alternateLeafSum(int arr[], int n){
    Node* root = NULL;
    for(int i=0;i<n;i++)
        root = insert(root, arr[i]);
    int ans = 0;
    bool isPrev = false;
    getLeafSum(root, isPrev, ans);
    return ans;
}
