// https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1/?track=SPC-Strings&batchId=154
string caseSort(string s, int n){
    int small[26] = {0};
    int cap[26] = {0};

    for(int i=0;i<n;i++){
        if((s[i]>='a') && (s[i]<='z'))
            small[s[i]-'a']++;
        else
            cap[s[i]-'A']++;
    }

    int pSmall = 0;
    int pCap = 0;

    for(int i=0;i<n;i++){
        if(s[i]>='a' && s[i]<='z'){
            while(small[pSmall]==0)
                pSmall++;
            s[i] = 'a'+pSmall;
            small[pSmall]--;
        }
        else{
            while(cap[pCap]==0)
                pCap++;
            s[i] = 'A'+pCap;
            cap[pCap]--;
        }
    }
    return s;
}
