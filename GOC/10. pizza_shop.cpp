int pizzaShop(int pizza[], int n, int topp[], int m, int x){
    vector<int> v;
    v.push_back(0);
    for(int i=0;i<m;i++){
        v.push_back(topp[i]);
        for(int j=(i+1);j<m;j++){
            v.push_back(topp[i]+topp[j]);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int ind = lower_bound(v.begin(), v.end(), x-pizza[i]) - v.begin();
        for(int j = (ind-1);j<(ind+2);j++){
            if(j>=0 && j<(int)v.size()){
                if(abs(pizza[i]+v[j]-x)<abs(ans-x))
                    ans = pizza[i]+v[j];
                else if(abs(pizza[i]+v[j]-x)==abs(ans-x))
                    ans = min(ans, pizza[i]+v[j]);
            }
        }
    }
    return ans;
}
