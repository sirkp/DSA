// selection sort
// time: O(n^2) extra_space: no
// not stable
void swap(int& a, int& b){
    a = a+b;
    b = a-b;
    a = a-b;
}


void getMin(int arr[], int j, int n){
    int minn = INT_MAX;
    int min_index = -1;
    for(int i=j;i<n;i++){
        if(arr[i]<minn){
            minn = arr[i];
            min_index = i;
        }
    }
    if(min_index!=j)
        swap(arr[min_index], arr[j]);
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n;i++){
        getMin(arr, i, n);
    }
}