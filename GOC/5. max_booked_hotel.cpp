int getPos(string s){
    int pos = (s[1]-'0');
    pos *= 26;
    pos += (int)(s[2]-'A');
    return pos;
}

string getStr(int i){
    string s;
    s += (char)((int)'0'+i/26);
    s += (char)((int)'A'+i%26);
    return s;
}

string maxBookHotel1(string arr[], int n){
    int hash[260] = {0};

    for(int i=0;i<n;i++){
        if(arr[i][0]=='+')
            hash[getPos(arr[i])]++;
    }

    int ind = -1;
    int val = -1;

    for(int i=0;i<260;i++){
        if(hash[i]>val){
            val = hash[i];
            ind = i;
        }
    }
    return getStr(ind);
}

string maxBookHotel2(string arr[], int n){
    unordered_map<string, int> hash;
    for(int i=0;i<n;i++){
        if(arr[i][0]=='+')
            hash[arr[i]]++;
    }
    
    int val = -1;
    string ans;
    for(auto x:hash){
        if(x.second>val || (x.second==val && x.first<ans)){
            ans = x.first;
            val = x.second;
        }
    }
    return ans.substr(1,2);
}
