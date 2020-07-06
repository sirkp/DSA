// https://practice.geeksforgeeks.org/problems/left-index-1587115620/1/?track=SPCF-Searching&batchId=154
int leftBound(int arr[], int i, int j, int x, int index){
    if(i<=j){
        int mid = (i+j)/2;
            
        if(x==arr[mid])
            index = mid;
        
        if(x<=arr[mid]){
            return leftBound(arr, i, (mid-1), x, index);
        }else{
            return leftBound(arr, (mid+1), j, x, index);
        }
    }
    else
        return index;
}

int leftIndex(int n, int arr[], int x){
    return leftBound(arr, 0, (n-1), x, -1);
}