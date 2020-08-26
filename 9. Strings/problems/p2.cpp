// https://practice.geeksforgeeks.org/problems/binary-string-1587115620/1/?track=SPC-Strings&batchId=154
long binarySubstring(int n, string s){
    long count = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
            count++;
    }   
    long ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            count--;
            ans += count;
        }
    }
    return ans;
}