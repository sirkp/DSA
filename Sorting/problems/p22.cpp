// https://practice.geeksforgeeks.org/problems/closer-to-sort-1587115620/1/?track=SPCF-Sorting&batchId=154
int binary_search(int arr[], int i, int j, int x, int n){
    if(i<=j){
        int mid = (i+j)/2;
        if(arr[mid]==x)
            return mid;
        if(((mid-1)>=0) && (arr[(mid-1)]==x))
            return (mid-1);
        if(((mid+1)<n) && (arr[(mid+1)]==x))
            return (mid+1);
        if(x>arr[mid])
            return binary_search(arr, (mid+1), j, x, n);
        else
            return binary_search(arr, i, (mid-1), x, n);
    }
    return -1;
}


int closer(int arr[],int n, int x){
    return binary_search(arr, 0, (n-1), x, n);
}