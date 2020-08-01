// insertion sort
// time: O(n^2)  extra_space: no
// stable

void shift(int arr[], int i, int n){
    int x = arr[n];
    for(int j=(n-1);j>=i;j--){
        arr[(j+1)] = arr[j];
    }
    arr[i] = x;
}

void insert(int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[n]){
            shift(arr, i, n);
            break;
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1])
            insert(arr, i);
    }
}
