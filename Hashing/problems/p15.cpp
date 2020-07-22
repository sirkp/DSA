// https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1/?track=SPCF-Hashing&batchId=154
vector <int> findPairs(int arr[], int n) {
    unordered_map<int, bool> hash;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(hash.find(arr[i]*-1)!=hash.end()){
            v.push_back(abs(arr[i])*-1);
            v.push_back(abs(arr[i]));
        }
        else
            hash[arr[i]] = false;    
    }
    return v;    
}