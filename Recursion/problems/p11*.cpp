// https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1/?track=SPCF-Recursion&batchId=154
void genPowerSet(string str, int i, string s, vector<string>& v){
    if(i==(int)str.size()){
        v.push_back(s);
        return;
    }
    genPowerSet(str, i+1, s+str[i], v);
    genPowerSet(str, i+1, s, v);
}

vector <string> powerSet(string s)
{
    vector<string> v;
    genPowerSet(s, 0, "", v);
    return v;
}
