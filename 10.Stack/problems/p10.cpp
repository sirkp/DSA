// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1/?track=SPC-Stack&batchId=154
int evaluatePostfix(string &s){
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int n2 = st.top();
            st.pop();
            int n1 = st.top();
            st.pop();
            if(s[i]=='*')
                st.push(n1*n2);
            else if(s[i]=='/')
                st.push(n1/n2);
            else if(s[i]=='+')
                st.push(n1+n2);
            else if(s[i]=='^')
                st.push((int)pow(n1, n2));
            else
                st.push(n1-n2);
        }
    }
    return st.top();
    
}
