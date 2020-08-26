// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1/?track=SPC-Strings&batchId=154
char getMaxOccuringChar(char* s){
    int i = 0;
    unordered_map<char, int> hash;
    while(s[i]!='\0'){
        if(hash.find(s[i])==hash.end())
            hash[s[i]] = 1;
        else
            hash[s[i]]++;    
        i++;
    }

    int maxCount = INT_MIN;
    char maxChar = 'a';
    for(auto x: hash)
        if(x.second>maxCount){
            maxCount = x.second;
            maxChar = x.first;
        }else if(x.second==maxCount){
            if(x.first<maxChar)
                maxChar = x.first;
        }
    return maxChar;    
}