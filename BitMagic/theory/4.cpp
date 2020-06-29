// https://practice.geeksforgeeks.org/problems/find-the-odd-occurence/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solveOptmised(){
	int n;
	cin>>n;
	int ans = 0;
	int temp;
	while(n--){
		cin>>temp;
		ans = ans ^ temp;
	}

	cout<<ans<<endl;
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
