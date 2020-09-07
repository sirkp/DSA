// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1/?track=DSASP-Graph&batchId=154
// https://leetcode.com/problems/rotting-oranges/
int rotOranges(vector<vector<int> > &adj, int m, int n){
    bool visited[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            visited[i][j] = false;
    queue<pair<int, int>> q;
    int time = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            if(adj[i][j]==2){
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
    }
    pair<int, int> null = make_pair(-1, -1);
    q.push(null);

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        if(p==null){
            if(q.size()>0){
                q.push(null);
                time++;
            }
        }else{
            int x = p.first, y = p.second;

            y = p.second - 1;

            if(x>=0 && x<m && y>=0 && y<n && adj[x][y]==1 && !visited[x][y]){
                visited[x][y] = true;
                q.push(make_pair(x, y));
            }

            y = p.second + 1;
            if(x>=0 && x<m && y>=0 && y<n && adj[x][y]==1 && !visited[x][y]){
                visited[x][y] = true;
                q.push(make_pair(x, y));
            }

            x = p.first - 1;
            y = p.second;
            if(x>=0 && x<m && y>=0 && y<n && adj[x][y]==1 && !visited[x][y]){
                visited[x][y] = true;
                q.push(make_pair(x, y));
            }

            x = p.first + 1;
            if(x>=0 && x<m && y>=0 && y<n && adj[x][y]==1 && !visited[x][y]){
                visited[x][y] = true;
                q.push(make_pair(x, y));
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1 && !visited[i][j])
                return -1;
        }
    }
    return time;
}
