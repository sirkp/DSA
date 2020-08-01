// Quick sort
// time:O(n^2) extra_space: no
// not stable   
// for random pivot, select a element from range swap it to last in lomuto and first in hoare

int lomutoPartition(int arr[], int low, int high){// lomuto partition
    int j = low - 1;
    for(int i=low;i<high;i++){
        if(arr[i]<=arr[high]){
            j++;
            swap(arr[i], arr[j]);
        }
    }
    j++;
    swap(arr[high], arr[j]);
    return j;    
}

void quickSortLomuto(int arr[], int low, int high){
    if(low<high){
        int p = lomutoPartition(arr, low, high);
        quickSortLomuto(arr, (p+1), high);    
        quickSortLomuto(arr, low, (p-1));    
    }
}

int hoarePartition(int arr[], int low, int high){
   int pivot = arr[low];
   int i = low-1, j = high+1;
   while(1){
        do{
           i++;
        }while(arr[i]<pivot);

        do{
           j--;
        }while(arr[j]>pivot);

        if(i>=j)
             return j;
        swap(arr[i], arr[j]);
    }
}

void quickSortHoare(int arr[], int low, int high){
    if(low<high){
        int p = hoarePartition(arr, low, high);
        quickSortHoare(arr, low, p);    
        quickSortHoare(arr, (p+1), high);    
    }
}
