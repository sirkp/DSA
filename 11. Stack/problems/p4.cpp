// https://practice.geeksforgeeks.org/problems/removing-consecutive-duplicates-1587115621/1/?track=SPC-Stack&batchId=154
string removeConsecutiveDuplicates(string str){
    stack<int> s;
    for(int i=0;i<str.size();i++){
        if(s.empty() || s.top()!=str[i]){
            s.push(str[i]);
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
