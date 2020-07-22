// https://practice.geeksforgeeks.org/problems/hashing-for-pair-1/1/?track=SPCF-Hashing&batchId=154
int sumExists(int arr[], int n, int sum){// Hashing method
    unordered_set<int> hash;
    for(int i=0;i<n;i++)
        hash.insert(arr[i]);

    for(int i=0;i<n;i++){
        if(hash.find(sum-arr[i])!=hash.end() && (*(hash.find(sum-arr[i]))!=arr[i]))
            return 1;
    }
    return 0;
}

int sumExists(int arr[], int n, int sum){// two pointer method
    sort(arr, arr+n);
    int i=0, j=n-1;
    while(i<j){
        if((arr[i]+arr[j])>sum)
            j--;
        else if((arr[i]+arr[j])<sum)
            i++;
        else
            return 1;        
    }
    return 0;
}