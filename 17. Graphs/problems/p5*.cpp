// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?track=DSASP-Graph&batchId=154
bool util(int v, int p, vector<int> adj[], bool visited[]){
    visited[v] = true;
    for(auto x: adj[v]){
        if((visited[x] && p!=x) || (!visited[x] && util(x, v, adj, visited)))
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int n){
   bool visited[n] = {false};
   for(int i=0;i<n;i++){
        if(!visited[i] && util(i ,-1, adj, visited))
            return true;
   }
   return false;
}