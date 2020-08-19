void printMaxMinGCD(vector<int> v){
    int high = -1;
    for(int i=0;i<(int)v.size();i++)
        high = max(high, v[i]);
    int divisor[high+1] = {0};

    for(int i=0;i<v.size();i++){
        int no = v[i];
        for(int i=1;i<=(int)sqrt(no);i++){
            if(no%i==0){
                divisor[i]++;
                if(i != (no/i))
                    divisor[(no/i)]++;
            }   
        }
    }
    int mx, mi=-1;
    for(int i=1;i<=high;i++){
        if(divisor[i]>=2){
            mx = i;
            if(mi==-1)
                mi = i;
        }
    }
    cout<<mx<<" "<<mi<<endl;
}

void maxGCD(vector<vector<int>> arr){
    vector<int> v;
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j+=2){
            if(arr[i][j]!=-1 && arr[i][j+1]!=-1){
                v.push_back(arr[i][j]);
                v.push_back(arr[i][j+1]);
            }
        }
    }
    printVector(v);
    if(v.size()==0){
        cout<<0<<endl;
    }else
        printMaxMinGCD(v);
}

void solve() {
    int n;
    cin>>n;
    if(n<1){
        cout<<0<<endl;
    }else{
        vector<vector<int>> arr;
        int no = 1;
        for(int i=0;i<=n;i++){
            vector<int> v;
            cinVector(v, no);
            arr.push_back(v);
            no *= 2;
        }
        maxGCD(arr);
    }
}
