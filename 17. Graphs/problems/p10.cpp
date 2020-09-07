// https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1/?track=DSASP-Graph&batchId=154
void dfs(int v, list<int> adj[], int& ans, int d){// O(V!)
    if(v==d)
        ans++;
    for(auto x: adj[v])
        dfs(x, adj, ans, d);
}

int countPaths(list<int> g[], int V, int s, int d) {
    int ans = 0;
    dfs(s, g, ans, d);
    return ans;
}