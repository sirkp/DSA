// https://practice.geeksforgeeks.org/problems/insertion-sort/1/?track=SPCF-Sorting&batchId=154
void shift(int arr[], int i, int n){
    int x = arr[n];
    for(int j=(n-1);j>=i;j--){
        arr[(j+1)] = arr[j];
    }
    arr[i] = x;
}

void insert(int arr[], int n){
    if(arr[n]<arr[n-1]){
        for(int i=0;i<n;i++){
            if(arr[i]>arr[n]){
                shift(arr, i, n);
                break;
            }
        }
    }
}