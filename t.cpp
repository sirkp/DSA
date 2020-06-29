#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n, string s=""){
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;    
}

void cinArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
}

int getMaxDigit(int arr[], int n){
    int maxx = -1;
    for(int i=0;i<n;i++)
        if(arr[i]>maxx)
            maxx = arr[i];
    return ((int)log2(maxx));        
}

int makeZero(int arr[], int n, int div){
    int c = 0;
    int temp;
    for(int i=0;i<n;i++){
        if(arr[i]>=div)
            c++;
    }
    if(c<=1){
        for(int i=0;i<n;i++){
            if(arr[i]>=div)
                arr[i] -= div;
        }
        temp = 0;    
    }
    else{
        for(int i=0;i<n;i++){
            arr[i] -= div;
            if(arr[i]<0)
                arr[i] = 0;
        } 
        temp = div;  
    }
}


void solve(){

    int n;
    cin>>n;
    
    int arr[n];
    cinArray(arr, n);
    cout<<maxAND(arr, n)<<endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int t = 1;
        cin>>t;
        while(t--){
            solve();
        }
}