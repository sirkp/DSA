// bellman ford
void relax(vector<pair<pair<int, int>, int>> edges, vector<int> &dist){
    int u, v, weight;
    for(int i=0;i<(int)edges.size();i++){
        u = edges[i].first.first;
        v = edges[i].first.second;
        weight = edges[i].second;
        if(dist[u]!=INT_MAX && dist[v]>(dist[u]+weight))
            dist[v] = dist[u] + weight;
    }
}

bool checkNegativeCycle(vector<pair<pair<int, int>, int>> edges, vector<int>& dist){
    int u, v, weight;
    for(int i=0;i<(int)edges.size();i++){
        u = edges[i].first.first;
        v = edges[i].first.second;
        weight = edges[i].second;
        if(dist[u]!=INT_MAX && dist[v]>(dist[u]+weight))
            return true;
    }
    return false;
}

vector<int> bellmanFord(int src, vector<pair<pair<int, int>, int>> edges, int V){// O(V*E)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0;i<(V-1);i++){
        relax(edges, dist);
    }

    if(checkNegativeCycle(edges, dist)){
        vector<int> temp;
        return temp;
    }else
        return dist;
}
