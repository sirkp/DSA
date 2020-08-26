// https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1/?track=SPCF-Matrix&batchId=154
void prepare(int arr[SIZE][SIZE], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] *= 2; 
        }
    }
}

int getVal(int arr[SIZE][SIZE], int i, int j){
    return (arr[i][j]/2);    
}

int getRemainder(int arr[SIZE][SIZE], int i, int j){
    return (arr[i][j]%2);
}

void printNewMatrix(int arr[SIZE][SIZE], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<getRemainder(arr, i, j)<<" ";
        }
        cout<<endl;
    }
}


void changeColRow(int arr[SIZE][SIZE], int m, int n, int ii, int jj, int row[], int col[]){
    if(col[jj]==0){
        col[jj] = 1;
        for(int i=0;i<m;i++){//col
            if(getRemainder(arr, i, jj)==0)
                arr[i][jj]++;
        }
    }
    if(row[ii]==0){   
        row[ii] = 1; 
        for(int j=0;j<n;j++){//row
            if(getRemainder(arr, ii, j)==0){
                arr[ii][j]++;
            }
        }
    }      
}

void booleanMatrix(int m, int n, int arr[SIZE][SIZE]){
    int row[m] = {0};
    int col[n] = {0};
    prepare(arr, m, n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(getVal(arr, i, j)==1){
                changeColRow(arr, m , n, i, j, row, col);
            }
        }
    }
    printNewMatrix(arr, m, n);    
}
