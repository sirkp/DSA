// https://practice.geeksforgeeks.org/problems/pangram-checking-1587115620/1/?track=SPC-Strings&batchId=154
bool checkPangram (string &s){
    char c;
    unordered_set<char> hash;
    for(int i=0;i<s.size();i++){
        c = s[i];
        if(s[i]>='A' && s[i]<='Z'){
            if((s[i]+32)>='a' && (s[i]+32)<='z')
                hash.insert((s[i]+32));
        }else if(s[i]>='a' && s[i]<='z')
            hash.insert(s[i]);
    }
    if(hash.size()==26)
        return true;
    else
        return false;    
}