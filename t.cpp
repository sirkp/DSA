#include<bits/stdc++.h>
using namespace std;

#define ll long long

void printArray(int arr[], int n, string s=""){
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;    
}

void cinArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
}

void cinVector(vector<int>& v, int n){
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }    
}

void printVector(vector<int>& v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

void showHash(unordered_map<char, int> hash){
    for(auto x: hash)
        cout<<x.first<<" "<<x.second<<endl;
}

void getCount(string s){
    int v = 0, b = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='v')
            v++;
        else if(s[i]=='b')
            b++;    
    }
    cout<<"v:"<<v<<"  b:"<<b<<"  ";
}

int printDistinct(char c){
    return (c-'a'+1);
}



void solve(){
    string s, p;
    cin>>s>>p;
    cout<<search(p, s)<<endl;
}


void test(){
    string s;
    cin>>s;
    int arr[s.size()];
}

void testCase(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        // test();
        testCase();
}