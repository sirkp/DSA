// https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/?track=SPC-Queue&batchId=154
vector<string> generate(ll n){
    vector<string> v;
    queue<string> q;
    v.push_back("1");
    q.push("1");
    string temp;
    while(v.size()<(int)n){
        temp = q.front();
        q.pop();
        v.push_back(temp+"0");
        q.push(temp+"0");
        if(v.size()<(int)n){
            v.push_back(temp+"1");
            q.push(temp+"1");
        }
    }
    return v;
}
