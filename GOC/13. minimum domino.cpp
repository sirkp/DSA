int numSwaps(int target, vector<int> arr1, vector<int> arr2){
    int n = 0;
    for(int i=0;i<(int)arr1.size();i++){
        if(arr1[i]!=target && arr2[i]!=target)
            return INT_MAX;
        else if(arr1[i]!=target){
            n++;
        }
    }
    return n;
}

int minDominoRotations(vector<int>& arr1, vector<int>& arr2) {
    int ans = min(numSwaps(arr1[0], arr1, arr2), numSwaps(arr2[0], arr1, arr2));
    ans = min(ans, numSwaps(arr1[0], arr2, arr1));
    ans = min(ans, numSwaps(arr2[0], arr2, arr1));
    return (ans==INT_MAX?-1:ans);
}