vector<int> maximumSubarray(int arr[], int n, int k){
    int ind = 0;
    for(int i=1;i<=(n-k);i++){
        if(arr[i]>arr[ind])
            ind = i;
    }

    vector<int> v;
    for(int i=ind;i<(ind+k);i++)
        v.push_back(arr[i]);
    return v;
}