// https://practice.geeksforgeeks.org/problems/quadratic-probing-in-hashing-1587115621/1/?track=SPCF-Hashing&batchId=154
int hashFn(int key, int m, int i){
    return (((key%m)+(i*i))%m);
}

void QuadraticProbing(vector <int>&v, int m, int arr[], int n){
    for(int i=0;i<m;i++)
        v[i] = -1;
    
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
        
}