// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/
void util(Node* node, int &i,  int x, int y, int &low, int &high, unordered_map<int, vector<pair<pair<int, int>, int>>> &hash){
    if(node){

        low = min(low, x);
        high = max(high, x);

        if(hash.find(x)==hash.end()){
            vector<pair<pair<int, int>, int>> v;
            v.push_back(make_pair(make_pair(y, i), node->data));
            hash[x] = v;
        }else
            hash[x].push_back(make_pair(make_pair(y, i), node->data));

        i++;

        util(node->left, i, x-1, y+1, low, high, hash);
        util(node->right, i, x+1, y+1, low, high, hash);
    }
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return (a.first.first<b.first.first || ((a.first.first==b.first.first) && (a.first.second<b.first.second)));
}

vector<int> verticalOrder(Node *root){
    int low = 0, high = 0, i = 0;
    unordered_map<int, vector<pair<pair<int, int>, int>>> hash;
    util(root, i, 0, 0, low, high, hash);

    vector<int> v;
    for(int i=low;i<=high;i++){
        sort(hash[i].begin(), hash[i].end(), compare);
        for(int j=0;j<(int)hash[i].size();j++)
            v.push_back(hash[i][j].second);
    }
    return v;
}
