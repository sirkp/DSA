// https://practice.geeksforgeeks.org/problems/rabin-karp-pattern-searching/1/?track=SPC-Strings&batchId=154
// Q(m+n), O(mn)

#define D 256 
bool search(string p, string s, int MOD) { 
    int n = s.size(), m = p.size();
    if(m>n)
        return false;

    int val = 1;
    for(int i=0;i<(m-1);i++)
        val = (val*D)%MOD;

    int sHash = 0;
    int pHash = 0;

    for(int i=0;i<m;i++){
        pHash = (D*pHash + p[i])%MOD;
        sHash = (D*sHash + s[i])%MOD;
    }

    if(sHash==pHash && compare(s, p, 0))
        return true;

    for(int i=1;i<=(n-m);i++){
        sHash = (sHash - val*s[i-1])%MOD;
        if(sHash<0)
            sHash += MOD;
        sHash = (D*sHash + s[i+m-1])%MOD;

        if(sHash==pHash && compare(s, p, i))
            return true;
    }
    return false;
} 
