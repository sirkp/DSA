// https://practice.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1/?track=SPCF-Matrix&batchId=154

void fill(int temp[N][N], int arr[N][N], int n, int k){
    for(int i=1;i<n;i++){
        int jj=0;
        for(int j=0;j<n;j++){
            if(j!=k){
                temp[(i-1)][jj] = arr[i][j];
                jj++;
            }
        }
    }
}

int determinantOfMatrix( int arr[N][N], int n){
    if(n==1)
        return arr[0][0];
    else{
        int det = 0;
        bool pos = true;
        for(int i=0;i<n;i++){
            
            int temp[N][N];
            fill(temp, arr, n, i);
            
            if(pos){
                det += (arr[0][i]*determinantOfMatrix(temp, (n-1)));
                pos = false;
            }else{
                det -= (arr[0][i]*determinantOfMatrix(temp, (n-1)));
                pos = true;
            }
        }
        return det;
    }    
    
}