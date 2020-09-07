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

void printVector(vector<int> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

void getSinkToSource(int u, vector<int> adj[], vector<bool>& visited, stack<int>& sinkToSource){
    visited[u] = true;
    for(auto v: adj[u])
        if(!visited[v])
            getSinkToSource(v, adj, visited, sinkToSource);
    sinkToSource.push(u);
}

void getRevAdj(vector<int> adj[], int V, vector<int> revAdj[]){
    for(int u=0;u<V;u++){
        for(auto v: adj[u])
            revAdj[v].push_back(u);
    }
}

void dfs(int u, vector<int> adj[], vector<bool>& visited){
    visited[u] = true;
    for(auto v: adj[u])
        if(!visited[v])
            dfs(v, adj, visited);
}

int kosarajuAlgo(vector<int> adj[], int V){
    vector<bool> visited(V, false);
    stack<int> sinkToSource;
    
    for(int i=0;i<V;i++){
        if(!visited[i])
            getSinkToSource(i, adj, visited, sinkToSource);
    }

    vector<int> revAdj[V];
    getRevAdj(adj, V, revAdj);

    for(int i=0;i<V;i++)
        visited[i] = false;

    int c = 0;
    while(!sinkToSource.empty()){
        int u = sinkToSource.top();
        sinkToSource.pop();
        if(!visited[u]){
            dfs(u, revAdj, visited);
            c++;
        }
    }
    return c;
}

void solve() {
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<kosarajuAlgo(adj, V)<<endl;
}

void test(){
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