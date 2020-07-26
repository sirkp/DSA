// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1/?track=SPC-Strings&batchId=154
string smallestWindow(string s, string p){
    int hash1[26] = {0};
    int hash2[26] = {0};
    for(int i=0;i<p.size();i++)
        hash1[p[i]-'a']++;

    int minLength = s.size()+1, length;
    int start=0, count = 0, low=-1;
    bool exists = false;
    for(int i=0;i<s.size();i++){
        if(hash1[s[i]-'a']){
            hash2[s[i]-'a']++;
            if(hash2[s[i]-'a']<=hash1[s[i]-'a'])
                count++;
        }

        if(count==p.size()){
            while(hash1[s[start]-'a']==0|| hash2[s[start]-'a']>hash1[s[start]-'a']){
                if(hash2[s[start]-'a']>hash1[s[start]-'a'])
                    hash2[s[start]-'a']--;
                start++;
            }
            length = i-start+1;
            if(length<minLength){
                minLength = length;
                low = start;
            }
        }
    }
    if(low==-1)
        return "-1";
    else
        return s.substr(low, minLength);
}
