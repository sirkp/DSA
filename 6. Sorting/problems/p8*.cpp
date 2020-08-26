// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/?track=SPCF-Sorting&batchId=154
long long int merge(long long int arr[], long long int low, long long int mid, long long int high, long long int inv){
    long long int n1 = mid-low+1;
    long long int n2 = high-mid;
    
    long long int left[n1];
    long long int right[n2];

    for(long long int i=0;i<n1;i++)
        left[i] = arr[(low+i)];
    
    for(long long int i=0;i<n2;i++)
        right[i] = arr[(mid+1+i)];

    long long int i = 0, j = 0;
    long long int k = low;
    while((i<n1) && (j<n2)){
        if(left[i]>right[j]){
            arr[k] = right[j];
            j++;
            inv += (n1-i);
        }else{
            arr[k] = left[i];
            i++;
        }
            k++;
    }

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    return inv;
}

long long int mergeSort(long long int arr[], long long int low, long long int high, long long int inv){
    if(low<high){
        long long int mid = (low+high)/2;
        inv = mergeSort(arr, low, mid, inv);
        inv = mergeSort(arr, (mid+1), high, inv);
        inv = merge(arr, low, mid, high, inv);
    }
    return inv;
}

long long int inversionCount(long long arr[], long long n){
    long long int inv = mergeSort(arr, 0, (n-1), 0);
    return inv;
}
