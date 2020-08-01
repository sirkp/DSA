// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1/?track=SPCF-Arrays&batchId=154
int maxIndexDiff(int arr[], int n) 
{ 
    int rightMax[n];
    rightMax[(n-1)] = arr[(n-1)];
    
    int maxx = arr[(n-1)];
    for(int i=(n-2);i>=0;i--){
        maxx = max(arr[i], maxx);
        rightMax[i] = maxx;    
    }
    
    int leftMax[n];
    leftMax[0] = arr[0];
    
    int minn = arr[0];
    for(int i=1;i<n;i++){
        minn = min(minn, arr[i]);
        leftMax[i] = minn;
    }
    
    int i=0;
    int j=0;
    maxx = -1;
    while(i<n&&j<n){
        if(rightMax[j]>=leftMax[i]){
            maxx = max(maxx, (j-i));
            j++;
        }
        else
            i++;
    }
    return maxx;
}
