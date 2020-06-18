// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


void solve(){// O(nlog(log(n)))
	int n;
    cin>>n;

    int arr[n+1] = {0};

    for(int i=2;(i*i)<=n;i++){
        int j = i*i;
        while(j<=n){
            arr[j] = 1;
            j += i;
        }
    }
    for(int i=2;i<=n;i++)
    if(arr[i]==0)
    cout<<i<<" ";
    cout<<endl;
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
