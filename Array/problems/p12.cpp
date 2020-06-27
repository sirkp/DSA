// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/?track=SPCF-Arrays&batchId=154
void mark(int arr[], int v, int i, int n){
    if(v>0 && v<=n){
        int index = v-1;
        // cout<<index;
        int temp = arr[index];
        arr[index] = -1;
        // cout<<" -> "<<temp<<" <-> "<<arr[index]<<endl;
        if(temp>0)
            mark(arr, temp, index, n);
    }        
}

void makeZero(int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]<0)
            arr[i] = 0;
    }
}

int missingNumber(int arr[], int n) { 
    
    makeZero(arr, n);
    
    int temp;
    for(int i=0;i<n;i++){
        if(arr[i]>0 && arr[i]<=n){
            temp = arr[i];
            // cout<<temp<<endl;
            arr[i] = 0;
            mark(arr, temp, i, n);
        }
    }
    // printArray(arr, n);
    for(int i=0;i<n;i++){
        if(arr[i]!=-1)
            return (i+1);    
    }
    
    return (n+1);
    
}