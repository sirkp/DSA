// https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1/?track=SPC-Strings&batchId=154
char nonrepeatingCharacter(string s){
    unordered_map<char, bool> hash;
    for(int i=0;i<s.size();i++)
        if(hash.find(s[i])==hash.end())
            hash[s[i]] = false;
        else    
            hash[s[i]] = true;

    for(int i=0;i<s.size();i++)
        if(!hash[s[i]])
            return s[i];
    return '$';       
}