// https://practice.geeksforgeeks.org/problems/remove-common-characters-and-concatenate-1587115621/1/?track=SPC-Strings&batchId=154
string concatenatedString(string s1, string s2) { 
    unordered_map<char, int> hash;
    for(int i=0;i<s1.size();i++)
        hash[s1[i]] = 1;

    for(int i=0;i<s2.size();i++)
        if(hash.find(s2[i])==hash.end())
            hash[s2[i]] = 2;
        else{
            if(hash[s2[i]]==1)
                hash[s2[i]] = 3;    
        }
    
    string s = "";
    for(int i=0;i<s1.size();i++)
        if(hash[s1[i]]!=3)
            s += s1[i];

    for(int i=0;i<s2.size();i++)
        if(hash[s2[i]]!=3)
            s += s2[i];
    if(s=="")
        s = "-1";
    return s;        
}
