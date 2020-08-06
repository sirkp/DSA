// https://practice.geeksforgeeks.org/problems/quick-sort/1/?track=SPCF-Sorting&batchId=154
int partition (int arr[], int low, int high){
    int j = low - 1;
    for(int i=low;i<high;i++){
        if(arr[i]<=arr[high]){
            j++;
            if(i!=j)
                swap(arr[i], arr[j]);
        }
    }
    j++;
    if(high!=j)
        swap(arr[high], arr[j]);
    return j;    
}