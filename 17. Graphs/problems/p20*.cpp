// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1/?track=DSASP-Graph&batchId=154
void dfsSinkToSource(int u, vector<int> adj[], bool visited[], stack<int>& s){
    visited[u] = true;
    for(auto v: adj[u]){
        if(!visited[v]){
            dfsSinkToSource(v, adj, visited, s);
        }
    }
    s.push(u);
}

void dfs(int u, vector<int> adj[], bool visited[]){
    visited[u] = true;
    for(auto v: adj[u])
        if(!visited[v])
            dfs(v, adj, visited);
}

vector<int>* reverseAdjList(vector<int> adj[], int V, vector<int> revAdj[]){
    for(int u=0;u<V;u++){
        for(auto v:adj[u])
            revAdj[v].push_back(u);
    }
}

int kosaraju(int V, vector<int> adj[]){
    bool visited[V] = {false};
    stack<int> s;
    for(int i=0;i<V;i++){
        if(!visited[i])
            dfsSinkToSource(i, adj, visited, s);
    }

    for(int i=0;i<V;i++)
        visited[i] = false;

    vector<int> revAdj[V];
    reverseAdjList(adj, V, revAdj);
    int count = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            dfs(u, revAdj, visited);
            count++;
        }
    }
    return count;
}