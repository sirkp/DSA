// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1/?track=SPC-Strings&batchId=154
bool areIsomorphic(string s1, string s2){
    if(s1.size()!=s2.size())
        return false;

    unordered_map<char, char> hash;
    unordered_set<char> marked;
    
    for(int i=0;i<s1.size();i++){
        if(hash.find(s1[i])==hash.end()){
            if(marked.find(s2[i])==marked.end()){
                hash[s1[i]] = s2[i];
                marked.insert(s2[i]);
            }else
                return false;
        }else{
            if(hash[s1[i]]!=s2[i])
                return false;
        }
    }
    return true;        
}
