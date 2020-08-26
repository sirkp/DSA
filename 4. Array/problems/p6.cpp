// https://practice.geeksforgeeks.org/problems/strongest-neighbour/1/?track=SPCF-Arrays&batchId=154
void maximumAdjacent(int n, int arr[]){
    
    for(int i=0;i<(n-1);i++){
        if(arr[i]>arr[i+1])
        cout<<arr[i]<<" ";
        else
        cout<<arr[i+1]<<" ";
    }
}