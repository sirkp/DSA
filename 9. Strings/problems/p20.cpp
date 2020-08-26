// https://practice.geeksforgeeks.org/problems/the-modified-string-1587115621/1/?track=SPC-Strings&batchId=154
int modified (string s){
    int c = 0;
    int n = 0;
    for(int i=0;(i+2)<=(int)s.size();i++){
        if(s[i+2]==s[i] && s[i+1]==s[i]){
            n++;
            i+=1;
        }
    }
    return n;
}