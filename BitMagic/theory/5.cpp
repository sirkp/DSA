// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0/


void solveBitMethod(){
	int n;
	cin>>n;

	int a = 1;
	for(int i=2;i<=n;i++)
	a = a ^ i;

	int b = 0;
	int temp;
	for(int i=0;i<(n-1);i++){
		cin>>temp;
		b = b ^ temp;
	}
	cout<<(a^b)<<endl;
}


void solveSumMethod(){
	int n;
	cin>>n;
	int sum = n;
	int temp;

	for(int i=0;i<(n-1);i++){
		cin>>temp;
		sum = sum - temp;
		sum = sum + (i+1);
	}

	cout<<sum<<endl;
}