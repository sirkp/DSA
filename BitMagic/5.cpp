// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solveSumMethod(){
	int n;
	cin>>n;
	int sum = n;
	int temp;

	for(int i=0;i<(n-1);i++){
		cin>>temp;
		sum = sum - temp;
		sum = sum + (i+1);
	}

	cout<<sum<<endl;
}

void solveBitMethod(){
	int n;
	cin>>n;

	int a = 1;
	for(int i=2;i<=n;i++)
	a = a ^ i;

	int b = 0;
	int temp;
	for(int i=0;i<(n-1);i++){
		cin>>temp;
		b = b ^ temp;
	}
	cout<<(a^b)<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	
	int t = 1;
	cin >> t;
	while(t--) {
	//   solveSumMethod();
	  solveBitMethod();
	}

	return 0;
}
