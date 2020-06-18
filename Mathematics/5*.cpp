// https://practice.geeksforgeeks.org/problems/lcm-and-gcd/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

long long int gcd(long long int a, long long int b){
	if(a==0)
	return b;
	else
	return gcd(b%a, a);
}

long long int lcm(long long int a, long long int b, long long int hcf){
    long long int n =  (a/hcf)*(b/hcf)*hcf;
    return n;
}

void solve(){// O(nlog(log(n)))
	long long int a,b;
    cin>>a>>b;

    long long int hcf = gcd(a,b);
    long long int l = lcm(a,b, hcf);
    cout<<l<<" "<<gcd(a,b)<<endl;
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
