// https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1/?track=SPCF-Matrix&batchId=154
int findMinOpeartion(int arr[][100], int n){
    int row = 0;
    for(int i=0;i<n;i++){
        int r = 0;
        for(int j=0;j<n;j++){
            r += arr[i][j];
        }
        row = max(row, r);
    }
    
    int col = 0;
    for(int j=0;j<n;j++){
        int c = 0;
        for(int i=0;i<n;i++){
            c += arr[i][j];
        }
        col = max(col, c);
    }
    int step = 0;
    if(row>col){
        for(int i=0;i<n;i++){
            int r = 0;
            for(int j=0;j<n;j++){
                r += arr[i][j];
            }
            step += (row-r);
        }
    }else{
        for(int j=0;j<n;j++){
            int c = 0;
            for(int i=0;i<n;i++){
                c += arr[i][j];
            }
            step += (col-c);
        }   
    }   
    return step;
}

