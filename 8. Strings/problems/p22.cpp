void getPos(int arr[], string s){
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++)
            if(s[j]<s[i])
                arr[i]++;
    }
}

// https://practice.geeksforgeeks.org/problems/rank-the-permutations-1587115621/1/?track=SPC-Strings&batchId=154
int findRank(string s) {
    int fact[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 227020758, 178290591, 674358851};
    unordered_set<char> hash;
    for(int i=0;i<s.size();i++)
        if(hash.find(s[i])!=hash.end())
            return 0;
        else
            hash.insert(s[i]);
    int pos[s.size()] = {0};
    getPos(pos, s);

    priority_queue<char, vector<char>, greater<char>> heap;
    for(int i=0;i<s.size();i++)
        heap.push(s[i]);

    long long int ans = 0;
    for(int i=0;i<s.size();i++){
        ans += (pos[i]*fact[(s.size()-i-1)])%MOD;
        // showpq(heap);
    }  
    return ans + 1;              
}
