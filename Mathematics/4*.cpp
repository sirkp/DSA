// https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int gcd(int a, int b){// O(log(min(a,b)))
	if(a==0)
	return b;
	else
	return gcd(b%a, a);
}

void solve(){// O(nlog(log(n)))
	int a,b;
    cin>>a>>b;

    cout<<gcd(a,b)<<endl;
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
