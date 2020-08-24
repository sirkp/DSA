// https://practice.geeksforgeeks.org/contest-problem/strange-median4247543704281248/1/
void util(Node* node, int &i, int k, Node* &nodeK){
    if(node){
        util(node->left, i, k, nodeK);
        if(i==k){
            nodeK = node;
            i++;
            return;
        }
        i++;
        util(node->right, i, k, nodeK);
    }
}

void inorder(Node* node, vector<int> &v){
    if(node){
        inorder(node->left, v);
        v.push_back(node->data);
        inorder(node->right, v);
    }
}

int median(Node *node,int k){
    int i = 1;
    Node* nodeK = NULL;
    util(node, i, k, nodeK);
    vector<int> v;
    inorder(nodeK, v);
    int n = (int)v.size();
    if(n%2==1)
        return v[n/2];
    else
        return ((v[(n/2)-1]+v[n/2])/2);
}