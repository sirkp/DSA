// https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1/?track=SPCF-Arrays&batchId=154/
// how to store both old and new value in a array, most important in replacement questions
long long storeVal(long long newVal, long long old, long long n){
    return ((newVal*n)+old);
}

long long getNewVal(long long v, long long n){
    return (v/n);
}

long long getOldVal(long long v, long long n){
    return (v%n);
}

void arrange(long long arr[], long long n){
    long long old, newVal;
    for(long long i=0;i<n;i++){
        old = arr[i];
        if(arr[i]<i){
            newVal = getOldVal(arr[arr[i]], n);
        } else{
            newVal = arr[old];
        }
        arr[i] = storeVal(newVal, old, n);
        // cout<<i<<" -> old: "<<old<<" newVal:"<<newVal<<" arr[i]"<<arr[i]<<endl;
    }

    for(long long i=0;i<n;i++){
        arr[i] = getNewVal(arr[i], n);
    }    
}