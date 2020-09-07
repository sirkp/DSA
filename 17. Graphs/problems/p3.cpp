// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/?track=DSASP-Graph&batchId=154
void util(int c, vector<int> g[], bool visited[], vector<int>& v){
    v.push_back(c);
    visited[c] = true;
    for(auto x: g[c])
        if(!visited[x])
            util(x, g, visited, v);
}

vector <int> dfs(vector<int> g[], int N){
    bool visited[N] = {false};
    vector<int> v;
    util(0, g, visited, v);
    return v;
}