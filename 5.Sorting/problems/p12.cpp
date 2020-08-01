// https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1/?track=SPCF-Sorting&batchId=154
bool findTriplets(int arr[], int n){ 
    sort(arr, arr+n);
    for(int i=(n-1);i>1;i--){
        int l=0, r=i-1;
        
        while(l<r){
            if((arr[l]+arr[r]+arr[i])>0)
                r--;
            else if((arr[l]+arr[r]+arr[i])<0)
                l++;
            else
                return true;
        }
    }
    return false;
}