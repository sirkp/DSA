// https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string-1587115621/1/?track=SPC-Strings&batchId=154
int findSum(string s){
	int sum = 0;
    int n = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            n = (n*10) + (s[i]-'0');
        }else{
            sum += n;
            n = 0;
        }
    }
    sum += n;
    return sum;
}