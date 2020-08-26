// https://practice.geeksforgeeks.org/problems/exchange-matrix-columns-1587115620/1/?track=SPCF-Matrix&batchId=154
void exchangeColumns(int n1, int m1, int arr1[SIZE][SIZE]){
    int temp;
    for(int i=0;i<n1;i++){
        temp = arr1[i][0];
        arr1[i][0] = arr1[i][(m1-1)];
        arr1[i][(m1-1)] = temp;
    }
}