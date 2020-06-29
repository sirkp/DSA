#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(n) for(int i=0;i<n;i++)
#define debug(x) cerr<< #x <<": "<<x<<endl;

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

bool isPerf(int n){
    if((n&(n-1))==0)
        return true;
    else
        return false;    
}

void print(bool ashish){// ashish = true
    if(ashish)
        cout<<"Ashishgup\n";
    else
        cout<<"FastestFinger\n";    
}

int getSmallest(int n){
    for(int i=3;i<=(n/2);i+=2){
        if(n%i==0)
            return (n/i);
    }
    return 0;
}


bool isPrime(int n){
    for(int i=2;i<=((int)sqrt(n));i++){
        if(n%i==0)
            return false;
    }
    return true;
}

void test(){
    loop(30){
        if(i>=2)
        cout<<i<<" -> "<<isPrime(i)<<endl;
    }
}

void solve(){
    int n;
    cin>>n;

    if(n==1)
        print(false);
    else if((n==2) || ((n%2)==1)){
        print(true);
    }
    else if(isPerf(n)){
        print(false);
    }
    else{
        if(isPrime(n/2))
            print(false);
        else
            print(true);    
                
    }    
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
        int t = 1;
        cin>>t;
        // test();
        while(t--){
            solve();
        }
}