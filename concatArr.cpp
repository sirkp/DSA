// concates and add same sign
// 1 2 3 4 5 -> 15, 1 2 -1 -> 3 -1, 1 -1 1 -> 1 -1 1
#include <bits/stdc++.h>
using namespace std;

void concat(int arr[], int n){
	int sum = arr[0];
	bool printed = true;
	for(int i=1;i<n;i++){
		if(!((sum>=0 && arr[i]>=0) || (sum<=0 && arr[i]<0))){
			cout<<sum<<" ";
			sum = 0;
			printed = true;
			
		}
			sum+=arr[i];
			printed = false;
	}
	if(!printed)
	cout<<sum;
	cout<<endl;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	concat(arr, n);
	
}