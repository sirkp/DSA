#include<bits/stdc++.h>
using namespace std;

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

int distributeChoclate(int arr[], int n, int k){
    k--;
    sort(arr, arr+n);
    int minn = INT_MAX;
    for(int i=0;(i+k)<n;i++){
        cout<<(arr[(i+k)]-arr[i])<<" ";
        minn = min(minn, (arr[(i+k)]-arr[i]));
    }
    cout<<endl;
    return minn;
}

void solve(){
    int n, m;
    cin>>n;
    int arr[n];
    cinArray(arr, n);
    cin>>m;
    cout<<distributeChoclate(arr, n, m)<<endl;
}

void test(){
    int n, x;
    cin>>n;
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
