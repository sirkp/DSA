// Counting Sort
// time:O(n+k) extra_space: O(n+k)
// stable in this implementation
void countSort(int arr[], int n){
    int high = *max_element(arr, arr+n);
    int low = *min_element(arr, arr+n);
    int range = high - low + 1;

    int countArray[range] = {0};

    for(int i=0;i<n;i++){
        countArray[arr[i]-low]++;
    }

    for(int i=1;i<range;i++)
        countArray[i] += countArray[(i-1)];


    int temp[n] = {0};
    for(int i=(n-1);i>=0;i--){
        temp[(countArray[(arr[i]-low)]-1)] = arr[i];
        countArray[(arr[i]-low)]--;
    }    

    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}
