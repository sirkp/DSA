// https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1/?track=SPCF-Hashing&batchId=154
int NumberofElementsInIntersection (int arr1[], int arr2[], int n, int m ){
    unordered_map<int, int> hash;
    for(int i=0;i<n;i++){
        hash[arr1[i]] = 1;
    }
    
    int count = 0;
    for(int i=0;i<m;i++){
        if(hash.find(arr2[i]) != hash.end()){
            if(hash[arr2[i]]==1){
                count++;
                hash[arr2[i]] = 3;
            }
        }else
            hash[arr2[i]] = 2;
    }
    return count;
}