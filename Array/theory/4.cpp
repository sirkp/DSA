// https://practice.geeksforgeeks.org/problems/maximum-difference/0
#include <iostream>
using namespace std;

int maxDifference(int arr[], int n){
    int diff = -1;
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>min){
            diff = diff>(arr[i]-min)?diff:(arr[i]-min);
        }
        if(arr[i]<min)
        min = arr[i];
    }
    return diff;
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
        cout<<maxDifference(arr, n)<<endl;
	}
	
	return 0;
}