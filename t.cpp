#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long
#define MOD 1000000007

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

void cinVectorPair(vector<pair<int, int>>& v, int n){
    int x, y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }    
}

void printVector(vector<int> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

void printVectorLL(vector<ll> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

void printVectorPair(vector<pair<int, int>> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i].first<<","<<v[i].second<<"  ";
    }    
    cout<<endl;    
}

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Coding Area Begin

class TrieNode{
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<26;i++)
            children[i] = NULL;
        isEndOfWord = false;
    }
}



// Coding Area End

void solve() {
    int n;
    cin>>n;
    int arr[n];
    cinArray(arr, n);
    segmentTree(arr, n);
}

vector<int> fn(){
    int arr[] = {1,2,3};
    vector<int> v{1,2,3};
    return v;
}

void test(){
    cout<<"**testing**\n"; 
    
    char str[] = "Geeks for   Geeks"; 
  
    char *token = strtok(str, " "); 
    string s;
    
    while (token != NULL) 
    {
        s = token; 
        cout<<s<<endl; 
        token = strtok(NULL, "-"); 
    } 

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