// https://practice.geeksforgeeks.org/problems/peak-element/1/?track=SPCF-Searching&batchId=154
int util(int arr[], int i, int j){
    if(i<=j){
        int mid = (i+j)/2;

        if((mid==i || (arr[mid-1]<=arr[mid])) && (mid==j || (arr[mid+1]<=arr[mid])))
            return mid;

        if(arr[mid+1]>=arr[mid])
            return util(arr, (mid+1), j);
        else
            return util(arr, i, (mid-1));        
    }
    return -1;
}

int peakElement(int arr[], int n) {
    return util(arr, 0, (n-1));
}