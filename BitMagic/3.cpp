// https://practice.geeksforgeeks.org/problems/power-of-2/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solveOptmised(){
	long long int n;
	long long int z = 0;
	long long int y = 1;
	cin>>n;
	if(n==0){
		cout<<"NO\n";
	}
	else{
		if ((n&(n-y))==z)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
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
	  solveOptmised();
	}

	return 0;
}
