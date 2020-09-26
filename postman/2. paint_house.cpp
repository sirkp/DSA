// build house paint ceiling
vector<long int> checkSmaller(vector<long int> v, long int s0){
    vector<long int> arr;
    for(auto x:v)
        if(x>=s0)
            arr.push_back(x);
    return arr;
}

vector<long int> getSet(long int n, long int s0, long int k, long int b, long int m){
    vector<long int> v(n, -1);
    v[0] = s0;
    for(long int i=1;i<n;i++){
        v[i] = (((k*v[i-1])+b)%m)+1+v[i-1];
    }
    return v;
}

long int variantsCount(long int n, long int s0, long int k, long int b, long int m, long int A){
    vector<long int> v = getSet(n, s0, k, b, m);
    long int ans = 0;
    for(long int i=0;i<(long int)v.size();i++){
        long int temp = A/v[i];
        long int ind = lower_bound(v.begin(), v.end(), temp)-v.begin();
        if(ind<(long int)v.size() && v[ind]==temp)
            ind++;
        ans += ind;
    }
    return ans;
}