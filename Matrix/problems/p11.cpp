// https://practice.geeksforgeeks.org/problems/reversing-the-columns-of-a-matrix-1587115621/1/?track=SPCF-Matrix&batchId=154
void exchangeColumns(int arr1[SIZE][SIZE], int n1, int m1, int j){
    int temp;
    for(int i=0;i<n1;i++){
        temp = arr1[i][j];
        arr1[i][j] = arr1[i][(m1-1-j)];
        arr1[i][(m1-1-j)] = temp;
    }
}

void reverseCol(int n1, int m1, int arr1[SIZE][SIZE])
{
    for(int i=0;i<(m1/2);i++)
        exchangeColumns(arr1, n1, m1, i);
}