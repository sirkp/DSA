// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1/?track=SPCF-Sorting&batchId=154

int ceil(int a, int b){
    return ((a/b)+(a%b));
}

int nextGap(int gap){
    if(gap<=1)
        return 0;
    return ceil(gap, 2);    
}

void merge(int arr1[], int arr2[], int m, int n){
    int N = m+n;
    int gap = N;
    gap = nextGap(gap);
    int j;
    while(gap>=1){
        for(int i=0;i<N;i++){
            j = i+gap;
            if(j<N){
                if((i<m)&&(j<m)){
                    if(arr1[i]>arr1[j])
                        swap(arr1[i], arr1[j]);
                }
                else if((i<m)&&(j>=m)){
                    if(arr1[i]>arr2[(j-m)])
                        swap(arr1[i], arr2[(j-m)]);
                }
                else{
                    if(arr2[(i-m)]>arr2[(j-m)])
                    swap(arr2[(i-m)], arr2[(j-m)]);    
                }
            }
        }
        gap = nextGap(gap);
    }

}
