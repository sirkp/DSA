// https://practice.geeksforgeeks.org/problems/count-1s-in-binary-array-1587115620/1/?track=SPCF-Searching&batchId=154
int reverseRightBound(int arr[], int i, int j, int x, int index){
    if(i<=j){
        
        int mid = (i+j)/2;
            
        if(arr[mid]==x)
            index = mid;
        
        if(x>=arr[mid])
            return reverseRightBound(arr, i, (mid-1), x, index);
        else
            return reverseRightBound(arr, (mid+1), j, x, index);
}
    else{
        return index;
    }
}

int countOnes(int arr[], int n){
    int c = reverseRightBound(arr, 0, (n-1), 0, -1);
    if(c==-1)
        return n;
    else
        return c;    
    
    
}
