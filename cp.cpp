#include<bits/stdc++.h>
using namespace std;

void printArray(long long arr[], int n, string s=""){
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;    
}

void cinArray(long long arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
}

int brut(string s){
    int res = 0;

    int init = 0;
    while(1){
        int cur = init;
        bool ok = true;
        for(int i=0;i<(int)s.size();i++){
            res = res + 1;
            if (s[i] == '+')
                cur = cur + 1;
            else
                cur = cur - 1;
            if (cur < 0){
                ok = false;
                break;  
            }
        }
        init++;
        if(ok)
            break;
    }  

    return res;
}

long long int optmised(string s){

    long long int res = 0;
    long long int min = 0;
    long long int c = 0;
    for(long long int i=0;i<(long long int)s.size();i++){
        if(s[i]=='-')
            c--;
        else
            c++;
        // cout<<c<<" ";
        if(c<min){
            min = c;
            res += (i+1);
        }        
    }

    // cout<<endl;
    res = (res+(long long int)s.size());
    return res;
}

void solve(){
    string s;
    cin>>s;
    // cout<<"brut: "<<brut(s)<<"  ";
    // cout<<"opt: "<<optmised(s)<<endl;
    cout<<optmised(s)<<endl;
    
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