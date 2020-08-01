// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <iostream>
using namespace std;

void isSubset(int arr[], int i, int n, int sum, int S, bool& is){
    
    if(sum==S)
    is = true;
    
    if(i==n){
        return;
    }
    
    isSubset(arr, i+1, n, sum+arr[i], S, is);
    isSubset(arr, i+1, n, sum, S, is);
}

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum += arr[i];
	    }
	    if(sum%2==0){
	        bool is = false;
	        isSubset(arr, 0, n, 0, sum/2, is);
	        
	        if(is)
	        cout<<"YES"<<endl;
	        else
	        cout<<"NO"<<endl;
	    }
	    else
	    cout<<"NO"<<endl;
	    
	    
	    
	}
	return 0;
}