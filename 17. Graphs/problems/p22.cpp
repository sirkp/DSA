// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1/?track=DSASP-Graph&batchId=154
void dfs(int u, list<int> adj[], vector<bool>& visited){
    visited[u] = true;
    for(auto v: adj[u])
        if(!visited[v])
            dfs(v, adj, visited);
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    vector<bool> visited(V, false);
    int c1 = 0;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, adj, visited);
            c1++;
        }
    }
    
    auto it = adj[s].begin();
    while((*it)!=e){
        it++;
    }
    adj[s].erase(it);

    it = adj[e].begin();
    while((*it)!=s){
        it++;
    }
    adj[e].erase(it);


    for(int i=0;i<V;i++)
        visited[i] = false;
    
    int c2 = 0;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, adj, visited);
            c2++;
        }
    }
    if(c2>c1)
        return true;
    else
        return false;
}

// articulation point method
// In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does
// not exist any other alternative to reach u or an ancestor of u from subtree rooted
// with v.
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

bool isBridge(list<int> adj[], int V, int s, int e) {
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, false);
    vector<pair<int, int>> bridge(V);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, -1, adj, visited, disc, low, bridge);
        }
    }

    for(auto p: bridge){
        if((p.first==s && p.second==e) || p.first==e && p.second==s)
            return true;
    }
    return false;
}

