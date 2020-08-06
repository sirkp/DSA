// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1/?track=SPCF-Sorting&batchId=154
vector<int> threeWayPartition(vector<int> v, int a, int b){
    int start = 0, end = (int)v.size()-1;
    int i = 0;
    while(i<=end){
        if(v[i]<a){
            swap(v[start], v[i]);
            start++;
            i++;
        } else if(v[i]>b){
            swap(v[end], v[i]);
            end--;
        } else
            i++;
    }
    return v;    
    
}