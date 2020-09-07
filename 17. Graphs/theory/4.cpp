// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/?track=DSASP-Graph&batchId=154
// Prime's Algo
int getMinKeyVertex(vector<int> &keys, vector<bool> &included){
    int m = INT_MAX;
    int v = -1;
    for(int i=0;i<(int)keys.size();i++){
        if(!included[i] && keys[i]<m){
            m = keys[i];
            v = i;
        }
    }
    // cout<<endl;
    return v;
}
int spanningTree(int V, int E, vector<vector<int>> &adj) {
    vector<bool> included(V, false);
    
    vector<int> keys(V, INT_MAX);// a way to find edge with minimum weight from included to not included
    keys[0] = 0;
    
    int minWeight = 0;

    for(int i=0;i<V;i++){
        int u = getMinKeyVertex(keys, included);
        included[u] = true;
        minWeight += keys[u];

        for(int j=0;j<(int)keys.size();j++){// update keys
            if(adj[u][j]!=INT_MAX && !included[j] && keys[j]>adj[u][j])
                keys[j] = adj[u][j];
        }
    }
    return minWeight;
}