
void dfs(int u, vector<int> adj[], vector<bool>& visited){
    visited[u] = true;
    for(auto v: adj[u])
        if(!visited[v])
            dfs(v, adj, visited);
}
// https://practice.geeksforgeeks.org/problems/mother-vertex/1/?track=DSASP-Graph&batchId=154
// mother vertices are always vertices of source component in component graph. 
int findMother(int V, vector<int> adj[]) { 
    vector<bool> visited(V, false);
    int src;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, adj, visited);
            src = i;
        }
    }
    
    for(int i=0;i<V;i++)
        visited[i] = false;

    dfs(src, adj, visited);

    for(int i=0;i<V;i++)
        if(!visited[i])
            return -1;
    
    return src;
} 