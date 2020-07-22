// https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1/?track=SPCF-Hashing&batchId=154
bool check(vector<ll> arr, vector<ll> brr, int n) {
    unordered_map<ll, int> hash;
    for(int i=0;i<n;i++){
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else
            hash[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(hash.find(brr[i])==hash.end())
            return false;
        else
            hash[brr[i]]--;
    }

    for(auto x: hash){
        if(x.second!=0)
            return false;
    }
    return true;
}