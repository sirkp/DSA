// https://practice.geeksforgeeks.org/problems/who-will-win-1587115621/1/?track=SPCF-Searching&batchId=154
int binary_search(int arr[], int i, int j, int x){
    if(i<=j){
        int mid = (i+j)/2;
        if(arr[mid]==x)
            return 1;
        if(x>arr[mid])
            return binary_search(arr, (mid+1), j, x);
        else
            return binary_search(arr, i, (mid-1), x);
    }
    return -1;
}

int searchInSorted(int arr[], int n, int K) 
{ 
    return binary_search(arr, 0, (n-1), K);
   // Your code here
   
}