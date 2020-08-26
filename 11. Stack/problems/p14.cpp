
vector <long long> nextLargerElement(long long arr[], int n){// without stack
    vector<long long> v(n, 1);
    int prev;
    for(int i=(n-1);i>=0;i--){
        prev = i+1;
        while(prev<n && arr[i]>=arr[prev]){
            v[i] += v[prev];
            prev += v[prev];
        }
    }
    // printVector(v);
    for(int i=0;i<n;i++){
        if((i+v[i])<n)
            v[i] = arr[i+v[i]];
        else
            v[i] = -1;
    }
    return v;
}

vector <long long> nextLargerElement(long long arr[], int n){
    vector<long long> v(n);
    stack<long long> s;
    for(int i=(n-1);i>=0;i--){
        while(!s.empty() && arr[i]>=s.top()){
            s.pop();
        }
        v[i] = (s.empty())?-1:s.top();
        s.push(arr[i]);
    }
    return v;
}