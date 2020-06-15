// https://practice.geeksforgeeks.org/problems/set-bits/0
// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void getLookupTable(int table[], int n){
	table[0] = 0;
	for(int i=1;i<n;i++)
	table[i] = ((i&1) + table[i/2]);
}

void solveNaive(){
	int n;
	cin>>n;
	int count = 0;
	while(n!=0){
		if(n%2==1)
		count++;
		n = n/2;
	}
	cout<<count<<endl;
}

void solveOptimised(){
	int n;
	cin>>n;
	int table[256] = {0};
	getLookupTable(table, 256);
	int count = table[n&0xff];
	n = n>>8;
	count += table[n&0xff];
	n = n>>8;
	count += table[n&0xff];
	n = n>>8;
	count += table[n&0xff];

	cout<<count<<endl;
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
	  solveOptimised();
    //   solveNaive();
	}

	return 0;
}
