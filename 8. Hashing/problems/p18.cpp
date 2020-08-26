// https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1/?track=SPCF-Hashing&batchId=154
long long int countSubarrWithEqualZeroAndOne(int arr[], int n){
    long long int count = 0;
    unordered_map<int, int> hash;

    if(arr[0]==0)
        arr[0] = -1;    
    
    hash[arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        if(arr[i]==1)
            arr[i] = arr[i-1] + 1;
        else
            arr[i] = arr[i-1] - 1;

        if(arr[i]==0)
            count++;
        count += hash[arr[i]];

        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else{
            hash[arr[i]]++;        
        }
    }    
    return count;
}
