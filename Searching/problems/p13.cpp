// https://practice.geeksforgeeks.org/problems/count-only-repeated/0/?track=SPCF-Searching&batchId=154
int findElement(int arr[], int i, int j, int n){
    if(i<=j){
        int mid = (i+j)/2;
        if( ((arr[mid]==arr[mid-1]) || mid==0) || ((arr[mid]==arr[mid+1]) || mid==(n-1)) )
            return arr[mid];

        if((arr[i]+(mid-i))==arr[mid])// right
            return findElement(arr, (mid+1), j, n);
        else
            return findElement(arr, i, (mid-1), n);
    }else
        return -1;
}

void repeatedElment(int arr[], int n){
    int e = findElement(arr, 0, (n-1), n);
    int no = (n+arr[0]-arr[(n-1)]);
    cout<<e<<" "<<no<<endl;
}
