// https://practice.geeksforgeeks.org/problems/prime-number/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void solve(){
	int n;
	cin>>n;
    bool isPrime = true;
    for(int i=2;i<=int(sqrt(n));i++){
        if(n%i==0){
            isPrime = false;
            break;
        }
    }
    if(isPrime && n!=1)
    cout<<"Yes\n";
    else
    cout<<"No\n";
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
