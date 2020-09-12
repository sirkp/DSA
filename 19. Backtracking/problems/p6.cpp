// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1/
bool isSafe(int no, int x, int y, int grid[N][N]){
    for(int i=0;i<N;i++){
        if(grid[i][y]!=0 && grid[i][y]==no)
            return false;
    }

    for(int j=0;j<N;j++){
        if(grid[x][j]!=0 && grid[x][j]==no)
            return false;
    }

    int xx = (x/3)*3, yy = (y/3)*3;

    for(int i=xx;i<(xx+3);i++){
        for(int j=yy;j<(yy+3);j++){
            if(grid[i][j]!=0 && grid[i][j]==no)
                return false;
        }
    }
    return true;
}

void util(int x, int y, int grid[N][N], bool& done){
    
    if(x==N && y==0){
        done = true;
        return;
    }
    if(grid[x][y]==0){
        for(int no=1;no<=9;no++){
            if(isSafe(no, x, y, grid)){
                grid[x][y] = no;
                if(y<(N-1))
                    util(x, y+1, grid, done);
                else
                    util(x+1, 0, grid, done);
            }
            if(done)
                return;
            grid[x][y] = 0;
        }
    }else {
        if(y<(N-1))
            util(x, y+1, grid, done);
        else
            util(x+1, 0, grid, done);
    }
}

bool SolveSudoku(int grid[N][N]){
    bool done = false;
    util(0, 0, grid, done);
    return done;
}

void printGrid (int grid[N][N]) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
    }
}
