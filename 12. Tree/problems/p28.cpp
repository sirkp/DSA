// https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1/?track=DSASP-Tree&batchId=154
void util(Node* node, int &ans, Node* minAncs, Node* maxAncs){
    if(node!=NULL){
        if(minAncs!=NULL && maxAncs!=NULL){
            ans = max(ans, (maxAncs->data-node->data));
            ans = max(ans, (minAncs->data-node->data));
            if(node->data>maxAncs->data)
                maxAncs = node;
            if(node->data<minAncs->data)
                minAncs = node;
        }else{
            maxAncs = node;
            minAncs = node;
        }
        util(node->left, ans, minAncs, maxAncs);
        util(node->right, ans, minAncs, maxAncs);
    }
}

int maxDiff(Node* root){
    int ans = INT_MIN;
    util(root, ans, NULL, NULL);
    return ans;
}