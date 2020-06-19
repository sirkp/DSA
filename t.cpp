// https://practice.geeksforgeeks.org/problems/modular-multiplicative-inverse/0
#include <bits/stdc++.h>
using namespace std;

void fn(vector<int>& v){
	v.push_back(3);
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	for(int i=0;i<(int)v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;
	fn(v);
	for(int i=0;i<(int)v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}