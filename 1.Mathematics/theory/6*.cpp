// https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<((n/5)+(n/25)+(n/125)+(n/625))<<endl;
	}
	return 0;
}