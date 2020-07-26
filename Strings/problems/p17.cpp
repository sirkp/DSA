// https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1/?track=SPC-Strings&batchId=154
int minIndexChar(string s, string patt){
    unordered_set<char> hash;
    for(int i=0;i<patt.size();i++){
        hash.insert(patt[i]);
    }

    for(int i=0;i<s.size();i++){
        if(hash.find(s[i])!=hash.end())
            return i;
    }
    return -1;
}