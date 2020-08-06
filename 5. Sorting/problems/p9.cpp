// https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1/?track=SPCF-Sorting&batchId=154
vector<int> findUnion(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> v;
    int i = 0;
    int j = 0;
    int k = 0;
    
    while((i<n1)&&(j<n2)){
        if(arr1[i]<arr2[j]){
            if((k==0) || (v[(k-1)]!=arr1[i])){
                v.push_back(arr1[i]);
                k++;
            }
                i++;
        }
        else{
            if((k==0) || (v[(k-1)]!=arr2[j])){
                v.push_back(arr2[j]);
                k++;
            }
                j++;
        }
    }
    
    while(i<n1){
        if((k==0) || (v[(k-1)]!=arr1[i])){
                v.push_back(arr1[i]);
                k++;
        }
                i++;
    }
    
    while(j<n2){
        if((k==0) || (v[(k-1)]!=arr2[j])){
                v.push_back(arr2[j]);
                k++;
        }
                j++;
    }
    return v;
}
