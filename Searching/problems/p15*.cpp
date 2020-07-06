// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0/?track=SPCF-Searching&batchId=154
long long int getSum(long long int arr[], long long int n){
    long long int sum = 0;
    for(long long int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;    
}

long long int maxOfArray(long long int arr[], long long int n){
    long long int maxx = 0;
    for(long long int i=0;i<n;i++){
        maxx = max(arr[i], maxx);
    }
    return maxx;
}

bool isPossible(long long int arr[], long long int n, long long int m, long long int minn){
    long long int noOfStudents = 1;
    long long int s = 0;
    for(long long int i=0;i<n;i++){
        if((s+arr[i])>minn){
            // cout<<s<<" ";
            noOfStudents++;
            s = 0;
        }
        s += arr[i];
    }
    if(noOfStudents>m)
        return false;    
    else
        return true;
}

long long int allocateMinimum(long long int arr[], long long int n, long long int m){
    long long int start = maxOfArray(arr, n);
    long long int end = getSum(arr, n);
    long long int res = -1;

    if(m>n)
        return -1;

    while(start<=end){
        long long int mid = (start+end)/2;
        if(isPossible(arr, n, m, mid)){
            res = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }    
    return res;
}
