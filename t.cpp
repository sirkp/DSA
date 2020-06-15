#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void getLookupTable(int table[], int n){
	table[0] = 0;
	for(int i=1;i<n;i++)
	table[i] = ((i&1) + table[i/2]);
}

int countSetBits(int table[], int n){
	int count = table[n&0xff];
	n = n >> 8;
	count += table[n&0xff];
	n = n >> 8;
	count += table[n&0xff];
	n = n >> 8;
	count += table[n&0xff];
	return count;
}

void solve(){
	int table[256] = {0};
	getLookupTable(table, 256);
	int n;
	cin>>n;
	int total_count = 0;
	for(int i=1;i<=n;i++)
	total_count += countSetBits(table, i);

	cout<<total_count<<endl;
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
