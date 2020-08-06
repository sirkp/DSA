// https://practice.geeksforgeeks.org/contest-problem/rolling-hash51043607553159092622/0/
#include<bits/stdc++.h>
using namespace std;

int getHash(char c){
    return (((int)c)-96);
}

void printHash(string s, int hash, int val, int size){
    vector<int> v;
    if(val==hash){
        v.push_back(0);
    }
    for(int i=1;i<=((int)s.size()-size);i++){
        val -= getHash(s[i-1]);
        val += getHash(s[i-1+size]);
        if(val==hash){
            v.push_back(i);
        }
    }
    
    if(((int)v.size())==0)
        cout<<-1<<endl;
    else{
        for(int i=0;i<(int)v.size();i++){
            cout<<s.substr(v[i], size)<<" "<<v[i]<<endl;
        }
    }

}

void solve(){
    string s, p;
    cin>>s;
    cin>>p;
    if(s.size()<p.size()){
        cout<<-1<<endl;
    }else{
        int hash = 0, val=0;
        for(int i=0;i<p.size();i++){
            hash += getHash(p[i]);
            val += getHash(s[i]);
        }
        printHash(s, hash, val, p.size());
    }
}


void testCase(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

int main() {
        testCase();
}