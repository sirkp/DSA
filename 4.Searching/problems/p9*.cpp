// https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1/?track=SPCF-Searching&batchId=154
int util(int arr[], int i, int j, int n){
    if(i<=j){
        int mid = (i+j)/2;
        if((mid==0 || arr[mid-1]>arr[mid]) && (mid==n || arr[mid+1]>arr[mid]))
            return arr[mid];
        
        if(arr[mid]<arr[j])
            return util(arr, i, (mid-1), n);
        else
            return util(arr, (mid+1), j, n);    
    }    
    else
        return -1;
}

int minNumber(int arr[], int i, int j){
    return util(arr, 0, j, j);
}