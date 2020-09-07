// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1/?track=DSASP-Graph&batchId=154
vector <vector <int> > nearest(vector<vector<int>> &mat, int m, int n) {
    vector <vector<int>> ans;
    for(int i= 0;i<m;i++){
        vector<int> v(n);
        ans.push_back(v);
    }

    vector <vector<bool>> visited;
    for(int i= 0;i<m;i++){
        vector<bool> v(n, false);
        visited.push_back(v);
    }

    queue<pair<int, int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                visited[i][j] = true;
                ans[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first, j = p.second;

        j = p.second-1;

        if(i>=0 && i<m && j>=0 && j<n && !visited[i][j]){
            visited[i][j] = true;
            ans[i][j] = ans[p.first][p.second]+1;
            q.push(make_pair(i, j));
        }

        j = p.second+1;
        if(i>=0 && i<m && j>=0 && j<n && !visited[i][j]){
            visited[i][j] = true;
            ans[i][j] = ans[p.first][p.second]+1;
            q.push(make_pair(i, j));
        }

        j = p.second;
        i = p.first-1;
        if(i>=0 && i<m && j>=0 && j<n && !visited[i][j]){
            visited[i][j] = true;
            ans[i][j] = ans[p.first][p.second]+1;
            q.push(make_pair(i, j));
        }

        i = p.first+1;
        if(i>=0 && i<m && j>=0 && j<n && !visited[i][j]){
            visited[i][j] = true;
            ans[i][j] = ans[p.first][p.second]+1;
            q.push(make_pair(i, j));
        }
    }

    return ans;

}