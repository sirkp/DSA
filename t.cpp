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
int lowerBound(int arr[], int n, int x) { 
    int mid; 
    int low = 0; 
    int high = n-1; 
    while (low < high) { 
        mid = low + (high - low) / 2; 
        if (x <= arr[mid]) { 
            high = mid; 
        } 
        else { 
            low = mid + 1; 
        } 
    } 
    return low; 
}

int upperBound(int arr[], int n, int x) { 
    int mid; 
    int low = 0; 
    int high = n-1; 
    while (low < high) { 
        mid = (low + high) / 2; 
        if (x >= arr[mid]) { 
            low = mid + 1; 
        } 
        else { 
            high = mid; 
        } 
    } 
    return low; 
} 

void solve(){
    int n, c;
    cin>>n;
    int arr[n];
    cinArray(arr, n);
    cout<<lowerBound(arr,n, 2)<<endl;
    cout<<upperBound(arr,n, 2)<<endl;
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
// https://practice.geeksforgeeks.org/contest-problem/kth-smallest-difference2936521057062451/0/