// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?track=DSASP-Graph&batchId=154
void dfs(int x, int y, int adj[SIZE][SIZE], int m, int n, int &count){
    count++;
    adj[x][y] = 0;
    for(int i=(x-1);i<=(x+1);i++){
        for(int j=(y-1);j<=(y+1);j++){
            if(i>=0 && j>=0 && i<m && j<n && adj[i][j]==1)
                dfs(i, j, adj, m, n, count);
        }
    }
}

int findMaxArea(int m, int n, int adj[SIZE][SIZE] ){
    int ans = 0;
    int count;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1){
                count = 0;
                dfs(i, j, adj, m, n, count);
                ans = max(ans, count);
            }
        }
    }
    return ans;
}
