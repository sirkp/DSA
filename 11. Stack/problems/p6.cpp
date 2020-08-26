// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1/?track=SPC-Stack&batchId=154
bool ispar(string x){
    stack<char> s;

    for(int i=0;i<x.size();i++){
        if(s.empty() || x[i]=='{' || x[i]=='(' || x[i]=='[')
            s.push(x[i]);
        else{
            if(x[i]==')' && s.top()=='(')
                s.pop();
            else if(x[i]==']' && s.top()=='[')
                s.pop();
            else if(x[i]=='}' && s.top()=='{')
                s.pop();
            else
                s.push(x[i]);
        }
    }
    return s.empty();
}
