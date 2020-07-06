// https://practice.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1/?track=SPCF-Searching&batchId=154
int search(int arr[], int n, int X){
    for(int i=0;i<n;i++)
        if(arr[i]==X)
            return i;
    return -1;        
}