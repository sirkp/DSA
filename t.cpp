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

void cinVector(vector<int>& v, int n){
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }    
}

void printVector(vector<int>& v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

struct petrolPump{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n){
    for(int i=0;i<n;i++)
        p[i].petrol -= p[i].distance;

    for(int i=0;i<n;i++)
        cout<<p[i].petrol<<" ";
    cout<<endl;
    
    int minus = 0;
    int sum = 0;
    int index = 0;
    for(int i=0;i<n;i++){
        if(sum<0){
            minus += sum;
            index = i;
            sum = 0;
        }
        sum += p[i].petrol;
    }
    if((sum+minus)<0)
        return -1;
    else
        return index;

}

void solve() {
}

void test(){
    stack<int> s;
    cout<<s.top();
}

void testCase(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        // test();
        testCase();
}