// https://practice.geeksforgeeks.org/problems/rearrange-characters5322/1/?track=DSASP-Heap&batchId=154
string rearrangeString(string s){
    unordered_map<char, int> hash;
    for(int i=0;i<(int)s.size();i++)
        if(hash.find(s[i])==hash.end())
            hash[s[i]] = 1;
        else
            hash[s[i]]++;
    
    priority_queue<pic> pq;
    for(auto x:hash){
        pq.push(make_pair(x.second, x.first));
    }

    int i = 0;
    while(!pq.empty()){
        pic a = pq.top();
        pq.pop();
        
        s[i] = a.second;
        i++;
        
        if(!pq.empty()){
            pic b = pq.top();
            pq.pop();

            s[i] = b.second;
            i++;

            b.first--;
            if(b.first>0)
                pq.push(b);
        }

        a.first--;
        if(a.first>0)
            pq.push(a);
    }
    return s;
}
