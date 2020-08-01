// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1/?track=SPCF-Sorting&batchId=154
vector<int> printIntersection(int arr1[], int arr2[], int n1, int n2){ 
    int i = 0;
    int j = 0;
    vector<int> v;

    while((i<n1) && (j<n2)){
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else{
            int n = (int) v.size();
            if((n==0) || (v[(n-1)]!=arr1[i])){
                v.push_back(arr1[i]);
            }
            i++;
            j++;
        }        
    }
    if((int)v.size()==0)
        v.push_back(-1);
    return v;
}
