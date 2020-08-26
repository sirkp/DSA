// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1/?track=SPC-Stack&batchId=154
string infixToPostfix(string s){
    stack<char> st;
    string ns = "";
    for(int i=0;i<s.size();i++){
        if((s[i]>='0'&&s[i]<='9') || (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
            ns += s[i];
        }else{
            if(st.empty() || s[i]=='(' || st.top()=='('){
                if(s[i]!=')')
                    st.push(s[i]);
            }
            else if(s[i]=='*' || s[i]=='/'){
                if(st.top()=='-' || st.top()=='+')
                    st.push(s[i]);
                else{
                    ns += st.top();
                    st.pop();
                    st.push(s[i]);
                }
            }else if(s[i]=='+' || s[i]=='-'){
                while(!st.empty() && st.top()!='('){
                    if(st.top()!='(')
                        ns += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }else if(s[i]=='^'){
                if(st.top()=='^'){
                    ns += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }else{
                while(st.top()!='('){
                    if(st.top()!='(')
                        ns += st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while(!st.empty()){
        if(st.top()!='(')
            ns += st.top();
        st.pop();
    }
    return ns;
}
