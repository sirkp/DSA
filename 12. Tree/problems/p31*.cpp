// https://practice.geeksforgeeks.org/problems/node-at-distance/1/?track=DSASP-Tree&batchId=154
void util(Node* node, vector<Node*> v, unordered_set<Node*> &visited, int k, int &ans){
    if(node!=NULL){
        if(node->left==NULL && node->right==NULL){
            if((int)v.size()>=k && visited.find(v[(int)v.size()-k])==visited.end()){
                ans++;
                visited.insert(v[(int)v.size()-k]);
            }
        }else{
            v.push_back(node);
            util(node->left, v, visited, k, ans);
            util(node->right, v, visited, k, ans);
        }
    }
}

int printKDistantfromLeaf(Node* root, int k){
    unordered_set<Node*> visited;
    vector<Node*> v;
    int ans = 0;
    util(root, v, visited, k, ans);
    return ans;
}