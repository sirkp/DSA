// https://practice.geeksforgeeks.org/problems/minimum-absloute-difference-between-adjacent-elements-in-a-circular-array-1587115620/1/?track=SPCF-Arrays&batchId=154
int getDiff(int arr[], int i, int n){
    if(i==(n-1))
        return abs(arr[(n-1)]-arr[0]);
    else
        return abs(arr[i]-arr[(i+1)]);
}

int minAdjDiff(int arr[], int n){    
    int min = INT_MAX;
    int temp;
    for(int i=0;i<n;i++){
        temp = getDiff(arr, i, n);
        if(temp<min)
        min=temp;
    }
    return min;
    
}