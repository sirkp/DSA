// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1/?track=SPCF-Sorting&batchId=154
bool find3Numbers(int arr[], int n, int x){
    sort(arr, arr+n);
    for(int i=(n-1);i>1;i--){
        int low = 0, high=(i-1);
        while(low<high){
            if((arr[low]+arr[high]+arr[i])>x)
                high--;
            else if((arr[low]+arr[high]+arr[i])<x)
                low++;
            else
                return true;    
        }
    }
    return false;
}