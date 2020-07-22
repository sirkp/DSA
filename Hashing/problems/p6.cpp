// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/?track=SPCF-Hashing&batchId=154
int firstRepeated(int arr[], int n) {
    unordered_map<int, bool> hash;
    for(int i=0;i<n;i++){
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = true;
        else
            hash[arr[i]] = false;    
    }
    for(int i=0;i<n;i++){
        if(!hash[arr[i]])
            return (i+1);
    }
    return -1;
}