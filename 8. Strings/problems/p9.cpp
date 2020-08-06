// https://practice.geeksforgeeks.org/problems/keypad-typing0119/1/?track=SPC-Strings&batchId=154
string printNumber(string s, int n) {
    string v;
    for(int i =0;i<n;i++){
        if(s[i]>='a' && s[i]<='c')
            v+='2';
        else if(s[i]>='d' && s[i]<='f')
            v+='3';    
        else if(s[i]>='g' && s[i]<='i')
            v+='4';    
        else if(s[i]>='j' && s[i]<='l')
            v+='5';    
        else if(s[i]>='m' && s[i]<='o')
            v+='6';    
        else if(s[i]>='p' && s[i]<='s')
            v+='7';    
        else if(s[i]>='t' && s[i]<='v')
            v+='8';    
        else if(s[i]>='w' && s[i]<='z')
            v+='9';    
    }
    return v;
}