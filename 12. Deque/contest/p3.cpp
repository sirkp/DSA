// https://practice.geeksforgeeks.org/contest-problem/closest-friends28530119593001232948/0/
#include<bits/stdc++.h>
using namespace std;

void cinArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
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

void testCase(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

int main() {
    testCase();
	return 0;
}