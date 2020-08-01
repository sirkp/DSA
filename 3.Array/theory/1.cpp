// https://practice.geeksforgeeks.org/problems/reverse-an-array/0
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n){
    for(int i=0;i<(n/2);i++){
        int temp = arr[n-1-i];
        arr[n-1-i] = arr[i];
        arr[i] = temp;
    }
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    reverse(arr, n);
	    for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}