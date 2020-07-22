// https://practice.geeksforgeeks.org/problems/print-distinct-elements-1587115620/1/?track=SPCF-Hashing&batchId=154
vector<int> printNonRepeated(int arr[],int n){
    vector<int> v;
    unordered_map<int, bool> hash;
    
    for(int i=0;i<n;i++){
        if(hash.find(arr[i])==hash.end()){
            hash[arr[i]] = true;
        }else
            hash[arr[i]] = false;
    }
    
    for(int i=0;i<n;i++){
        if(hash[arr[i]]){
            v.push_back(arr[i]);
        }
    }
    return v;
}