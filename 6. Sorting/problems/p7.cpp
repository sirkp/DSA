// https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1/?track=SPCF-Sorting&batchId=154
int getOneIndex(int arr[], int n, int start){
    for(int i=start;i<n;i++)
        if(arr[i]==1)
            return i;
    return n;        
}

int getZeroIndex(int arr[], int n, int start){
    for(int i=start;i>=0;i--)
        if(arr[i]==0)
            return i;
    return -1;        
}

void binSort(int arr[], int n){
    int i = getOneIndex(arr, n, 0);
    int j = getZeroIndex(arr, n, (n-1));

    while(i<j){
        swap(arr[i], arr[j]);
        i = getOneIndex(arr, n, (i+1));
        j = getZeroIndex(arr, n, (j-1));
    }
    
}