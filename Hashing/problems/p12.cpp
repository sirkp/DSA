// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1/?track=SPCF-Hashing&batchId=154
bool subArrayExists(int arr[], int n){
    unordered_map<int, bool> hash;

    for(int i=1;i<n;i++){
        arr[i] = arr[i]+arr[i-1];
    }

    for(int i=0;i<n;i++){
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = false;
        else
            hash[arr[i]] = true;
    }

    for(auto x: hash)
        if(x.first==0 || x.second)
            return true;
    return false;
}
