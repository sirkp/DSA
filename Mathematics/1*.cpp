// finding no of digits in a number
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int getNoOfDigits(int n){
    return (log10(n)+1);
}

void solve(){
	int n;
	cin>>n;
    cout<<getNoOfDigits(n)<<endl;
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
	  solve();
	}

	return 0;
}
