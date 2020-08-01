// https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1/?track=SPCF-Hashing&batchId=154
int subArraySum(int arr[], int n, int sum){
    int count = 0;
    unordered_map<int, int> hash;
    if(arr[0]==sum)
        count++;
    hash[arr[0]] = 1;    

    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
        if(arr[i]==sum)
            count++;

        if(hash.find(arr[i]-sum)!=hash.end())
            count += hash[arr[i]-sum];

        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else
            hash[arr[i]]++;    
    }
    return count;
}