// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1/?track=SPCF-Hashing&batchId=154
ll findSubarray(vector<ll> arr, int n ) {
    long long count = 0;
    unordered_map<ll, ll> hash;
    hash[arr[0]] = 1;
    if(arr[0]==0)
        count++;

    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
        if(arr[i]==0)
            count++;
        
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else{
            count += hash[arr[i]];
            hash[arr[i]]++;
        }    
    }
    return count;
}