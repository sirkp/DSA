// https://leetcode.com/problems/n-queens/

bool isSafe(int x, int y, int n, vector<string>& grid){
    for(int i=0;i<x;i++){// col
        if(grid[i][y]=='Q')
            return false;
    }

    int i=x-1, j=y-1;// pos diagonal
    while(i>=0 && j>=0 && i<n && j<n){
        if(grid[i][j]=='Q')
            return false;
        i--;
        j--;
    }

    i=x-1, j=y+1;
    while(i>=0 && j>=0 && i<n && j<n){
        if(grid[i][j]=='Q')
            return false;
        i--;
        j++;
    }
    return true;

}

void util(int x, int n, vector<string>& grid, vector<vector<string>>& ans, bool& done){
    if(x==n){
        ans.push_back(grid);
        return;
    }else{
        for(int y=0;y<n;y++){
            if(isSafe(x, y, n, grid)){
                grid[x][y] = 'Q';
                util(x+1, n, grid, ans, done);
                if(done)
                    return;
                grid[x][y] = '.';
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> grid; 
    for(int i=0;i<n;i++){
        string temp(n, '.');
        grid.push_back(temp);
    }
    // print(grid);
    bool done = false;
    util(0, n, grid, ans, done);
    return ans;
}
