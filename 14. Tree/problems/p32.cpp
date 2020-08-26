// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/?track=DSASP-Tree&batchId=154
pair<int, int> util(Node* node){
    if(node!=NULL){
        pair<int, int> l = util(node->left);
        pair<int, int> r = util(node->right);
        
        return make_pair((l.second+r.second+node->data), (max(l.first, l.second)+max(r.first,r.second)));

    }else
        return make_pair(0, 0);
}

int getMaxSum(Node *root) {
    pair<int, int> p = util(root);
    return max(p.first, p.second);
}