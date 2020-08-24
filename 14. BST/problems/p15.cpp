// https://www.hackerrank.com/challenges/tree-top-view/problem
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
void util(Node* node, int x, int y, int &low, int &high, unordered_map<int, pair<int, int>> &hash){
    if(node){
        low = min(low, x);
        high = max(high, x);

        if(hash.find(x)==hash.end()){
            pair<int, int> p = make_pair(y, node->data);
            hash[x] = p;
        }else
            if(y<hash[x].first)
                hash[x] = make_pair(y, node->data);

        util(node->left, x-1, y+1, low, high, hash);
        util(node->right, x+1, y+1, low, high, hash);
    }
}

void topView(Node *root){
    int low = 0, high = 0;
    unordered_map<int, pair<int, int>> hash;
    util(root, 0, 0, low, high, hash);

    vector<int> v;
    for(int i=low;i<=high;i++){
        cout<<hash[i].second<<" ";
    }
}
