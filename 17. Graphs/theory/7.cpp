// Articulation Point
void dfs(int u, int parent, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<bool>& ap){
    static int time = 0;
    visited[u] = true;

    int child = 0;
    disc[u] = low[u] = ++time;

    for(auto v: adj[u]){
        if(!visited[v]){
            child++;
            dfs(v, u, adj, visited, disc, low, ap);
            
            low[u] = min(low[u], low[v]);

            if(parent==-1 && child>1)
                ap[u] = true;
            
            if(parent!=-1 && low[v]>=disc[u])
                ap[u] = true;

        }else if(v!=parent)
            low[u] = min(low[u], disc[v]);
    }
}

void articulationPoint(vector<int> adj[], int V){
    vector<int> disc(V);// store discovery time of vertices
    vector<int> low(V);// lowest discovery time vertex reachable from a vertex
    vector<bool> visited(V, false);
    vector<bool> ap(V, false);

    for(int i=0;i<V;i++)
        if(!visited[i])
            dfs(i, -1, adj, visited, disc, low, ap);

    for(int i=0;i<V;i++)
        if(ap[i])
            cout<<i<<" ";
    cout<<endl;
}
