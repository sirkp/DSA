// https://practice.geeksforgeeks.org/problems/separate-chaining-in-hashing-1587115621/1/?track=SPCF-Hashing&batchId=154
vector<vector<int>> separateChaining(int m,int arr[],int n){
    vector<vector<int>> v;
    vector<int> temp;    
    for(int i=0;i<m;i++){
        v.push_back(temp);
    }
       
    int index;
    for(int i=0;i<n;i++){
        index = hashFn(arr[i], m);
        v[index].push_back(arr[i]);
    }
    return v;
}