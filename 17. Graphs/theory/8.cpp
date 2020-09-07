// All bridges
void dfs(int u, int parent, list<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<pair<int, int>>& bridge){
    static int time = 0;
    visited[u] = true;
    
    disc[u] = low[u] = ++time;

    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v, u, adj, visited, disc, low, bridge);
            
            low[u] = min(low[u], low[v]);

            if(low[v]>disc[u]){
                bridge.push_back(make_pair(u, v));
            }

        }else if(v!=parent)
            low[u] = min(low[u], disc[v]); 
    }
}

void isBridge(list<int> adj[], int V, int s, int e) {
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, false);
    vector<pair<int, int>> bridge(V);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, -1, adj, visited, disc, low, bridge);
        }
    }

}
    