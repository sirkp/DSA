// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1/?track=SPCF-Hashing&batchId=154
int doUnion(int arr1[], int n, int arr2[], int m)  {
    unordered_map<int, int> hash;
    for(int i=0;i<n;i++){
        hash[arr1[i]] = 1;
    }
    for(int i=0;i<m;i++){
        hash[arr2[i]] = 1;
    }
    return ((int)hash.size());
}