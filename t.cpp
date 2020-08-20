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

void printVector(vector<int> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl<<endl;    
}


void nearestLeft(int arr[], int n){
    vector<int> v(n, 1);
    for(int i=1;i<n;i++){
        int j = i-1;
        while(j>=0 && arr[j]>=arr[i]){
            v[i] += v[j];
            j -= v[j];
        }
    }
    for(int i=0;i<n;i++)
        cout<<i-v[i]<<" ";
    cout<<endl;
}

void solve() {
    int n;
    cin>>n;
    int arr[n];
    cinArray(arr, n);
    nearestLeft(arr, n);
}


void test(){

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