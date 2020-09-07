// https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1/?track=DSASP-Graph&batchId=154
void dfs(int x, int y, vector<string>& adj, int m, int n){
    adj[x][y] = 'O';
    int i=x, j=y;
    
    i = x+1;
    if((i>=0 && i<m) && (j>=0 && j<n) && adj[i][j]=='X')
        dfs(i, j, adj, m, n);
    
    i = x-1;
    if((i>=0 && i<m) && (j>=0 && j<n) && adj[i][j]=='X')
        dfs(i, j, adj, m, n);
    
    i=x, j=y+1;
    if((i>=0 && i<m) && (j>=0 && j<n) && adj[i][j]=='X')
        dfs(i, j, adj, m, n);
    
    j = y-1;
    if((i>=0 && i<m) && (j>=0 && j<n) && adj[i][j]=='X')
        dfs(i, j, adj, m, n);
}

int Shape(vector<string> &arr, int m, int n) {
    vector<string> adj = arr;
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]=='X'){
                dfs(i, j, adj, m, n);
                ans++;
            }
        }
    }

    return ans;
}
