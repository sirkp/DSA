// https://practice.geeksforgeeks.org/problems/hashing-for-pair-2/1/?track=SPCF-Hashing&batchId=154
int sumExists(int arr[], int n, int sum){
    unordered_map<int, bool> hash;
    for(int i=0;i<n;i++)
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = false;
        else
            hash[arr[i]] = true;

    for(int i=0;i<n;i++){
        if(hash.find(sum-arr[i])!=hash.end() && (hash.find(sum-arr[i])->first!=arr[i] || hash.find(sum-arr[i])->second)){
            return 1;
        }
    }
    return 0;
}
