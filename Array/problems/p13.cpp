// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1/?track=SPCF-Arrays&amp;batchId=154
int getIndex(int i, int n){
    if(i<n/2)
        return ((2*i)+1);
    else
        return (2*(n-1-i));    
}

void swap(long long& a, long long& b){
    a = a+b;
    b = a-b;
    a = a-b;
}

int getNewStartIndex(long long arr[], int n, int prevStartIndex){
    for(int i=(prevStartIndex+1);i<n;i++){
        if(arr[i]>0)
            return i;
    }
    return n;
}

void rearrange(long long *arr, int n) {
    int index = 0;
    int count = 0;
    long long temp;
    while(count<n){
        int i = index;
        long long val = arr[i];
        i = getIndex(i, n);
        swap(arr[i], val);
        arr[i] = arr[i]*(-1);
        count++;
        while(count<n && index!=i){
            i = getIndex(i, n);
            swap(arr[i], val);
            arr[i] = arr[i]*(-1);
            count++;
        } 
        index = getNewStartIndex(arr, n, index);
    }

    for(int i=0;i<n;i++){
        arr[i] *= (-1);
    }
}
