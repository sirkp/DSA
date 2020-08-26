// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
void util(Node* node, int x, int y, unordered_map<int, pair<int, int>> &hash, int &low, int &high){
    if(node){
        util(node->left, x-1, y+1, hash, low, high);
        
        low = min(low, x);
        high = max(high, x);

        if(hash.find(x)==hash.end())
            hash[x] = make_pair(y, node->data);
        else
            if(y>=hash[x].first)
                hash[x] = make_pair(y, node->data);

        util(node->right, x+1, y+1, hash, low, high);
    }
}

vector <int> bottomView(Node *root){
    int low = 1, high = -1;
    unordered_map<int, pair<int, int>> hash;
    util(root, 0, 0, hash, low, high);
    vector<int> v;
    for(int i=low;i<=high;i++)
        v.push_back(hash[i].second);
    return v;
}
