// https://practice.geeksforgeeks.org/problems/topological-sort/1/?track=DSASP-Graph&batchId=154
void util(int u, vector<int> adj[], bool visited[], vector<int> &v){
    visited[u] = true;
    for(auto x: adj[u]){
        if(!visited[x])
            util(x, adj, visited, v);
    }
    v.push_back(u);
}

vector<int> topoSort(int n, vector<int> adj[]) {
    vector<int> v;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(!visited[i])
            util(i, adj, visited, v);
    }
    reverse(v.begin(), v.end());
    return v;
}