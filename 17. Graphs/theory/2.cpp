// https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

// Shortest Path in Directed Acyclic Graph
// Given a Weighted Directed Acyclic Graph and a source vertex in the graph,
// find the shortest paths from given source to all other vertices.
void util(int u, vector<pair<int, int>> adj[], bool visited[], vector<int> &v){
    visited[u] = true;
    for(auto x: adj[u]){
        if(!visited[x.first])
            util(x.first, adj, visited, v);
    }
    v.push_back(u);
}

vector<int> topoSort(int n, vector<pair<int, int>> adj[]) {
    vector<int> v;
    bool visited[n] = {false};
    for(int i=0;i<n;i++){
        if(!visited[i])
            util(i, adj, visited, v);
    }
    reverse(v.begin(), v.end());
    return v;
}

void shortestPathDAG(pair<pair<int, int>, int> pairs[], int vertices, int edges, int source){// pairs: (x,y)->weight
    vector<pair<int, int>> adj[vertices];
    for(int i=0;i<edges;i++){
        adj[pairs[i].first.first].push_back(make_pair(pairs[i].first.second, pairs[i].second));
    }

    vector<int> top = topoSort(vertices, adj);
    
    vector<int> dist(vertices, INT_MAX);

    dist[source] = 0;


    // we traverse in topological sort order to make sure that there are no backward edge 
    for(int i=0;i<vertices;i++){
        for(auto p: adj[top[i]]){
            if(dist[i]!=INT_MAX && dist[p.first]>(dist[i] + p.second))
                dist[p.first] = dist[i] + p.second;
        }
    }

    printVector(dist);
}

void solve() {
    int vertices, edges, source;
    cin>>vertices>>edges>>source;
    pair<pair<int, int>, int> pairs[edges];
    for(int i=0;i<edges;i++){
        int x, y, w;
        cin>>x>>y>>w;

        pairs[i] = make_pair(make_pair(x, y), w);
    }

    shortestPathDAG(pairs, vertices, edges, source);
}
