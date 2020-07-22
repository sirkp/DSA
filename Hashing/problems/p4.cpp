// https://practice.geeksforgeeks.org/problems/count-distinct-elements-1587115620/1/?track=SPCF-Hashing&batchId=154
int countNonRepeated(int arr[], int n){
    unordered_map<int, bool> hash;
    
    for(int i=0;i<n;i++){
        if(hash.find(arr[i])==hash.end()){
            hash[arr[i]] = true;
        }else
            hash[arr[i]] = false;
    }
    
    int count =0;
    for(auto x: hash)
        if(x.second)
            count++;
    return count;
}