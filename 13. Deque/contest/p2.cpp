// https://practice.geeksforgeeks.org/contest-problem/pairing-the-brackets28550121593201252950/0/
#include<bits/stdc++.h>
using namespace std;

void leftBracket(string s){
    int l = -1;
    int n = (int)s.size();
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            l++;
            while(l<i){
                if(s[l]=='('){
                    v.push_back(make_pair(l, i));
                    break;
                }
                l++;
            }
        }
    }
    cout<<(int)v.size()<<endl;
    for(int i=0;i<(int)v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
}

void solve() {
    string s;
    cin>>s;
    leftBracket(s);
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