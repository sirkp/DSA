// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1/?track=SPCF-Searching&batchId=154
int util(vector<long long>arr, long long i, long long j, long long x, int index){
    if(i<=j){
        int mid = (i+j)/2;
        if(x==arr[mid])
            return mid;
        else if(x<arr[mid])
            return util(arr, i, (mid-1), x, index);
        else{
            index = mid;
            return util(arr, (mid+1), j, x, index);
        }
    }else
        return index;
}

int findFloor(vector<long long> arr, long long n, long long x){
   return util(arr, 0, (n-1), x, -1);
}