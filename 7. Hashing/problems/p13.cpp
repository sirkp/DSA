// https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/?track=SPCF-Hashing&batchId=154
pair <string,int> winner(string arr[],int n){
    unordered_map<string, int> hash;
    for(int i=0;i<n;i++){
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else    
            hash[arr[i]]++;
    }

    pair<string, int> p("a", -1);
    for(auto x: hash){
        if(x.second>p.second || (x.second==p.second && x.first<p.first))
            p = x;
    }
    return p;
}