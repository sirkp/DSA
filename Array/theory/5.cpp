// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
#include <iostream>
using namespace std;

void stock(int arr[], int n){
    bool buyed = false;
    bool everBuyed = false;
    for(int i=0;i<(n-1);i++){
        if(!buyed && (arr[i+1]>arr[i])){//buy
            buyed = true;
            everBuyed = true;
            cout<<"("<<i<<" ";
        }
        if(buyed && arr[i+1]<arr[i]){// sell
            buyed = false;
            cout<<i<<") ";
        }
    }
    if(buyed){
        cout<<(n-1)<<") ";
    }
    if(!everBuyed)
    cout<<"No Profit";
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
        cin>>n;
        
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        stock(arr, n);
        cout<<endl;
	}
	return 0;
}