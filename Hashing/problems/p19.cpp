// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1/?track=SPCF-Hashing&batchId=154
void sortA1ByA2(int arr1[], int n, int arr2[], int m) {
    unordered_map<int, int> hash;
    for(int i=0;i<n;i++){
        if(hash.find(arr1[i])==hash.end())
            hash[arr1[i]] = 1;
        else
            hash[arr1[i]]++;
    }
    int count = 0;
    for(int i=0;i<m;i++){
        if(hash.find(arr2[i])!=hash.end()){
            int j = 0;
            while(j<hash[arr2[i]]){
                arr1[count] = arr2[i];
                count++;
                j++;
            }
            hash[arr2[i]] = 0;
        }
    }
    int c = count;
    for(auto x: hash){
        int j = 0;
        while(j<x.second){
            arr1[count] = x.first;
            count++;
            j++;
        }
    }
    sort(arr1+c, arr1+n);    
}
