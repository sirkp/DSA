int fn(string s){
    int arr[26] = {0};
    
    for(int i=0;i<(int)s.size();i++)
        arr[s[i]-'a']++;
    
    for(int i=0;i<26;i++)
        if(arr[i]!=0)
            return arr[i];
    return 0;
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> q;
    for(int i=0;i<(int)queries.size();i++){
        q.push_back(fn(queries[i]));
    }
    
    vector<int> w;
    for(int i=0;i<(int)words.size();i++){
        w.push_back(fn(words[i]));
    }
    
    sort(w.begin(), w.end());
    
    int ind;
    for(int i=0;i<(int)q.size();i++){
        q[i] = lower_bound(w.begin(), w.end(), q[i]) - w.begin();
    }
    return q;
}