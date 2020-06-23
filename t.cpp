#include<bits/stdc++.h>
using namespace std;

void swap(vector<long long>& v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void reverse(vector<long long>& arr, int start, int end){// [start, end]
    while(start<end){
        swap(arr, start, end);
        start++;
        end--;
    }
}

int getEnd(int i, int k, int n){
    if((i+k)<n)
        return (i+k-1);
    else
        return (n-1);    
}

vector<long long> reverseInGroups(vector<long long> arr, int n, int k){
    int i=0;
    int end;
    while(i<n){
        end = getEnd(i, k, n);
        reverse(arr, i, end);
        i = end+1;
    }
    return arr;
}

void print(vector<long long> v){
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<long long> arr;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            arr.push_back(temp);
        }
        // print(arr);
        arr = reverseInGroups(arr, n, k);
        print(arr);
    }
    

}