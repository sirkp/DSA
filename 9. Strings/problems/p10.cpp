// https://practice.geeksforgeeks.org/problems/repeating-character-first-appearance-leftmost/1/?track=SPC-Strings&batchId=154
int repeatedCharacter(string s){ 
    unordered_map<char, bool> hash;
    for(int i=0;i<s.size();i++)
        if(hash.find(s[i])==hash.end())
            hash[s[i]] = false;
        else    
            hash[s[i]] = true;

    for(int i=0;i<s.size();i++)
        if(hash[s[i]])
            return i;
    return -1;        
} 