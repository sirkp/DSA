// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/
void util(int x, int y, vector<int> arr[], int n, int m){
    arr[x][y] = 0;
    for(int i=(x-1);i<=(x+1);i++){
        for(int j=(y-1);j<=(y+1);j++){
            if(i>=0 && i<n && j>=0 && j<m && !(i==x && j==y) && arr[i][j]==1)
                util(i, j, arr, n, m);
        }
    }    
}

int findIslands(vector<int> arr[], int n, int m) {
    int c = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                util(i, j, arr, n, m);
                c++;
            }
        }
    }
    return c;
}