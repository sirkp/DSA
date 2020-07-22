// https://practice.geeksforgeeks.org/problems/linear-probing-in-hashing-1587115620/1/?track=SPCF-Hashing&batchId=154
int hashFn(int key, int m, int i){
    return (((key%m)+i)%m);
}

vector<int> linearProbing(int m, int arr[], int n){
    vector<int> v(m, -1);
    for(int i=0;i<n;i++){
        int key = arr[i];
        int j = 0;
        int index = hashFn(key, m, j);
        int first = index;
        while(v[index]!=-1 && (j==0 || index!=first)){
            j++;
            index = hashFn(key, m, j);
        }
        if(v[index]==-1)
            v[index] = key;
    }    
    return v;
    
}