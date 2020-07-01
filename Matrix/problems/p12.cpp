// https://practice.geeksforgeeks.org/problems/reversing-the-rows-of-a-matrix-1587115621/1/?track=SPCF-Matrix&batchId=154
void exchange(int arr[SIZE][SIZE], int m, int n, int j){
    int temp;
    for(int i=0;i<n;i++){
        temp = arr[j][i];
        arr[j][i] = arr[(m-1-j)][i];
        arr[(m-1-j)][i] = temp;
    }
}

void interchangeRows(int m, int n, int arr[SIZE][SIZE])
{
    for(int i=0;i<(m/2);i++)
        exchange(arr, m, n, i);
}
