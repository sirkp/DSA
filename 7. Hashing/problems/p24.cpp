// https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays/0
int longestSubarrayWithSumK(int arr[], int n, int k){
    unordered_map<int, int> hash;// (sum, index)

    int sum = 0, count = 0, c = 0;
    for(int i=0;i<n;i++){
        c=0;
        sum += arr[i];
        if(sum == k){
            c = i+1;
        }
        else{
            if(hash.find(sum-k)!=hash.end())
                c = i - hash[sum-k];
        }

        if(hash.find(sum)==hash.end())
            hash[sum] = i;
        count = max(c, count);
    }
    return count;
}

int longestSpan(int arr[], int brr[], int n){
    for(int i=0;i<n;i++)
        arr[i] = arr[i] - brr[i];

    return longestSubarrayWithSumK(arr, n, 0);    
}
