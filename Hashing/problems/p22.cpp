// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1
vector<int> countDistinct (int arr[], int n, int k){
    unordered_map<int, int> hash;
    vector<int> v;
    for(int i=0;i<k;i++){
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else
            hash[arr[i]]++;    
    }
    v.push_back(hash.size());

    for(int i=1;i<=(n-k);i++){
        if(hash[arr[i-1]]==1)
            hash.erase(arr[i-1]);
        else
            hash[arr[i-1]]--;

        if(hash.find(arr[i+k-1])==hash.end())
            hash[arr[i+k-1]] = 1;
        else
            hash[arr[i+k-1]]++;        

        v.push_back(hash.size());
    }

    return v;
}
