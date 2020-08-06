// https://practice.geeksforgeeks.org/problems/modular-multiplicative-inverse/0
#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y){
	if(a==0){
		(*x) = 0;
		(*y) = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b%a, a, &x1, &y1);
	(*x) = y1 - ((b/a)*x1);
	(*y) = x1;
	return gcd;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
	    int a,M;
	    cin>>a>>M;
		if (M==1)
    	cout<<-1<<endl;
		int x, y;
	    int gcd = gcdExtended(a, M, &x, &y);
		if(gcd!=1)
		cout<<-1<<endl;
		else
		cout<<(((x%M)+M)%M)<<endl;    
	}
	return 0;
}