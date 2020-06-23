// https://practice.geeksforgeeks.org/problems/quick-left-rotation/0
#include <iostream>
using namespace std;

int getIndex(int i, int n, int k){
    i = i-k;
    if(i<0){
        i = i + n;
    }
    return i;
}

void moveLeft(int arr[], int n, int k){
    int count = 0;
    int index = 0;
    while(count!=n){
        int i = index;
        int x = arr[i];
        int j;
        while(count!=n){
            j = getIndex(i, n, k);
            int y = arr[j];
            arr[j] = x;
            count++;
            x = y;
            i = j;
            if(i==index)
            break;
        }
        index++;
    }
}

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n, k;
        cin>>n>>k;
        
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        
        moveLeft(arr, n, k%n);
        
        for(int i=0;i<n;i++)
    	cout<<arr[i]<<" ";
    	cout<<endl;
           
	}
	return 0;
}