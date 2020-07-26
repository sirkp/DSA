// https://practice.geeksforgeeks.org/problems/distinct-pattern-search-1587115620/1/?track=SPC-Strings&batchId=154
bool search(string p, string s) { 
    int n = s.size(), m = p.size();
    int i = 0, j=0;
    while(i<n){
        if(s[i]==p[j]){
            i++;
            j++;

            if(j==m)
                return true;
        }else{
            if(j==0)
                i++;
            j=0;
        }
    }
    return false;

} 
