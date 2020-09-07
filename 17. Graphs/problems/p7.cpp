// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1/?track=DSASP-Graph&batchId=154
bool util(int x, int y, vector<vector<int>> &adj){
    int n = (int)adj.size();
    if(adj[x][y]==2)
        return true;
    adj[x][y] = 0;
    if((y+1)<n && adj[x][y+1]!=0 && util(x, (y+1), adj))
        return true;
    else if((y-1)>=0 && adj[x][y-1]!=0 && util(x, (y-1), adj))
        return true;
    else if((x+1)<n && adj[x+1][y]!=0 && util((x+1), y, adj))
        return true;
    else if((x-1)>=0&& adj[x-1][y]!=0 && util((x-1), y, adj))
        return true;
    else
        return false;
}

bool is_possible(vector <vector <int>> &adj, int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(adj[i][j]==1 && util(i, j, adj)){
                return true;
            }
        }
    return false;
}