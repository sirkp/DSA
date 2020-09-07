// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?track=DSASP-Graph&batchId=154
bool util(int v, vector<int> adj[], bool visited[], bool reckStack[]){
    visited[v] = true;
    reckStack[v] = true;

    for(auto x: adj[v]){
        if(reckStack[x] || (!visited[x] && util(x, adj, visited, reckStack)))
            return true;
    }
    reckStack[v] = false;
    return false;
}

bool isCyclic(int n, vector<int> adj[]){
    bool visited[n] = {false};
    bool reckStack[n] = {false};

    for(int i=0;i<n;i++){
        if(reckStack[i] || (!visited[i] && util(i, adj, visited, reckStack)))
            return true;
    }
    return false;
}