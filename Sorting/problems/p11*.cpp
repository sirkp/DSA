// https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1/?track=SPCF-Sorting&batchId=154
long long findNumberOfTriangles(long long n){
    long long count = 0;
    sort(arr, arr+n);

    for(long long i = (n-1);i>1;i--){
        long long l=0, r=(i-1);
        while(l<r){
            if((arr[l]+arr[r])>arr[i]){
                count += (r-l);
                r--;
            }else
                l++;
        } 
    }
    return count;
}