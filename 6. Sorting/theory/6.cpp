// Merge sort
// Time: O(nlogn) extra_space: O(n)
// stable: depends on implemenation
// in this implementation it is not stable, if we do left[i]<=right[j] in line 21, then it becomes stable
void merge(int arr[], int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;

    int left[n1], right[n2];
    
    for(int i=0;i<n1;i++)
        left[i] = arr[low+i];

    for(int i=0;i<n2;i++)
        right[i] = arr[mid+1+i];

    int i = 0;
    int j = 0;
    int k = low;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
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
}

void mergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, (mid+1), high);
        merge(arr, low, mid, high);
    }
}
