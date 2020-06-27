// https://practice.geeksforgeeks.org/problems/maximum-occured-integer4602/1/?track=SPCF-Arrays&batchId=154
int getMax(int arr[], int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = arr[i]+sum;
        arr[i] = sum;
    }
    int max_index = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[max_index])
            max_index = i;
    }
    return max_index;
}

int maxOccured(int L[], int R[], int n, int maxx){
    int hash[(maxx+1)] = {0};
    for(int i=0;i<n;i++){
        hash[L[i]] += 1;
        hash[(R[i]+1)] -= 1;
    }
    return getMax(hash, (maxx+1));
}