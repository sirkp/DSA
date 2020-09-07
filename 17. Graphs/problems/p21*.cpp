// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1/?track=DSASP-Graph&batchId=154
int shortest(vector<vector<int> > &adj, int n) {
    vector<vector<int>> dist;
    for(int i=0;i<n;i++){
        vector<int> temp(n, INT_MAX);
        dist.push_back(temp);
    }
    vector<vector<bool>> finished;
    for(int i=0;i<n;i++){
        vector<bool> temp(n, false);
        finished.push_back(temp);
    }

    dist[0][0] = adj[0][0];

    multimap<int, pair<int, int>> mp;

    mp.insert({dist[0][0], make_pair(0, 0)});

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    while(!mp.empty()){
        auto e = mp.begin();
        int weight = e->first;
        int x = e->second.first, y = e->second.second;
        mp.erase(mp.begin());
        finished[x][y] = true;

        int i,j;
        for(int k=0;k<4;k++){
            i = x+dx[k];
            j = y+dy[k];
            if(i<n && j<n && i>=0 && j>=0 && !finished[i][j] && dist[i][j]>(dist[x][y]+adj[i][j])){
                auto ptr = mp.find(dist[i][j]);
                if(ptr!=mp.end()){
                    mp.erase(ptr);
                }
                dist[i][j] = dist[x][y] + adj[i][j];
                mp.insert({dist[i][j], make_pair(i, j)});
            }
        }
    }
    return dist[n-1][n-1];
}
