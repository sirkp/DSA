// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?track=DSASP-Graph&batchId=154
// Dijkastra
// below implementation complexity is O(V*V)

// If adjacency list is given and we implement using Min Heap and
// a mechanism to get index of a value Then O(VlogV + ElogV)
// same complexity can be achieved using BST(map)
#define INF INT_MAX

int getMin(vector<int> dist, vector<bool> done){
    int m = INT_MAX;
    int index = -1;

    for(int i=0;i<(int)dist.size();i++){
        if(!done[i] && dist[i]<m){
            m = dist[i];
            index = i;
        }
    }
    return index;
}

vector <int> dijkstra(vector<vector<int>> adj, int src, int n){
    vector<int> dist(n, INF);
    dist[src] = 0;


    vector<bool> done(n, false);
    int c = 0;
    while(c<n){

        int u = getMin(dist, done);
        done[u] = true;
        c++;

        for(int i=0;i<n;i++){
            if(!done[i] && adj[u][i]!=0 && dist[i]>(dist[u]+adj[u][i])){
                dist[i] = dist[u] + adj[u][i];
            }
        }
    }
    return dist;

}