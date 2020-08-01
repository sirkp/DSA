// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s-1587115621/1/?track=SPCF-Sorting&batchId=154
void segragate012(int arr[], int n){
    int start = 0, end = (n-1), i = 0;
    
    while(i<=end){
        if(arr[i]<1){
            swap(arr[i], arr[start]);
            start++;
            i++;
        } else if(arr[i]>1){
            swap(arr[i], arr[end]);
            end--;
        }
        else
            i++;
    }
}
