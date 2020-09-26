

vector<int> strictlyIncNonDec(vector<int> arr){
    sort(arr.begin(), arr.end());
    int i=1, j=2, n=(int)arr.size();
    while(i<(n/2)){
        if(arr[i]<=arr[i-1]){
            j = max(i+1, j);
            while(j<n){
                if(arr[j]>arr[i-1])
                    break;
                j++;
            }
            if(j==n){
                sort(arr.begin()+i, arr.end(), greater<int>());
                while(i<(n/2)){
                    arr[i] = arr[i-1]+1;
                    i++;
                }
                break;
            }else{
                swap(arr[i], arr[j]);
            }
        }
        i++;
    }
    sort(arr.begin()+(n/2), arr.end());
    return arr;
}
