// https://practice.geeksforgeeks.org/problems/power-of-2/0

void isPowerOf2(long long int n){
	long long int z = 0;
	long long int y = 1;
	if(n==0){
		cout<<"NO\n";
	}
	else{
		if ((n&(n-y))==z)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
}
