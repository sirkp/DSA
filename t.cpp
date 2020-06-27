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

int maxIndexDiff(int arr[], int n) 
{ 
    int rightMax[n];
    rightMax[(n-1)] = arr[(n-1)];
    
    int maxx = arr[(n-1)];
    for(int i=(n-2);i>=0;i--){
        maxx = max(arr[i], maxx);
        rightMax[i] = maxx;    
    }
    
    int leftMax[n];
    leftMax[0] = arr[0];
    
    int minn = arr[0];
    for(int i=1;i<n;i++){
        minn = min(minn, arr[i]);
        leftMax[i] = minn;
    }
    
    int i=0;
    int j=0;
    maxx = -1;
    while(i<n&&j<n){
        if(rightMax[j]>=leftMax[i]){
            maxx = max(maxx, (j-i));
            j++;
        }
        else
            i++;
    }
    return maxx;
}

void solve(){
    int n;
    cin>>n;

    int arr[n];
    cinArray(arr, n);
    
    cout<<maxIndexDiff(arr, n)<<endl;    
    // printArray(arr, n);
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