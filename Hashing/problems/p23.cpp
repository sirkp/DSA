// https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
int maxLen(int arr[], int n){
    unordered_map<int, int> hash;
    int count = 0, c;

    if(arr[0]==0)
        arr[0] = -1;

    hash[arr[0]] = 0;

    for(int i=1;i<n;i++){
        c = 0;
        if(arr[i]==0)
            arr[i] = arr[i-1] + -1;
        else
            arr[i] = arr[i-1] + 1;

        if(arr[i]==0)
            c = i+1;
        else{
            if(hash.find(arr[i])!=hash.end())
                c = i - hash[arr[i]];
            else
                hash[arr[i]] = i;    
        }            
        count = max(c, count);
    }    
    return count;
}
