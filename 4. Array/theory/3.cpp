// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/1/?track=SPCF-Arrays&batchId=155
vector<int> leaders(int arr[], int n){
    
    vector<int> v;
    v.push_back(arr[n-1]);
    int max = arr[n-1];
    for(int i=(n-2);i>=0;i--){
        if(arr[i]>=max){
            max = arr[i];
            v.push_back(max);
        }
    }
    reverse(v.begin(), v.end());
    return v; 
}