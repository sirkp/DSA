// https://practice.geeksforgeeks.org/problems/removing-consecutive-duplicates-2-1587115621/1/?track=SPC-Stack&batchId=154
string removePair(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(s.empty() || s.top()!=str[i]){
            s.push(str[i]);
        }else{
            s.pop();
        }
    }
    string newStr = "";
    while(!s.empty()){
        newStr += s.top();
        s.pop();
    }
    reverse(newStr.begin(), newStr.end()); 
    return newStr;
}
