// https://practice.geeksforgeeks.org/problems/pattern-search-kmp/1/?track=SPC-Strings&batchId=154
void computeLPSArray(string s, int m, int lps[]){ 
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i<m){
        if(s[i]==s[len]){
            len++;
            lps[i] = len;
            i++;
        }else if(len==0){
            lps[i] = 0;
            i++;
        }else
            len = lps[len-1];
    }
} 

bool KMPSearch(string p, string s) {
    int n = s.size();
    int m = p.size();
    int lps[m];
    computeLPSArray(p, m, lps);

    int i = 0, j = 0;
    while(i<n){
        if(s[i]==p[j]){
            i++;
            j++;

            if(j==m)
                return true;
        }else{
            if(j==0)
                i++;
            else
                j = lps[j-1];    
        }
    }
    return false;
}
