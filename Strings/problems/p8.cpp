// https://practice.geeksforgeeks.org/problems/check-if-a-string-is-isogram-or-not-1587115620/1/?track=SPC-Strings&batchId=154
bool isIsogram(string s){
    unordered_set<char> hash;

    for(int i=0;i<s.size();i++)
        if(hash.find(s[i])==hash.end())
            hash.insert(s[i]);
        else
            return false;
    return true;        
}