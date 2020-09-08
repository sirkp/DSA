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
        arr[i]--;
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

void printGraph(vector<int> adj[], int n){
    for(int i=0;i<n;i++){
        cout<<i;
        printVector(adj[i]);
    }
    
}

int getMin(vector<int> dist, vector<bool> done){
    int m = INT_MAX;
    int index = -1;

    for(int i=0;i<(int)dist.size();i++){
        if(!done[i] && dist[i]<m){
            m = dist[i];
            index = i;
        }
    }
    return index;
}


int dijkstra(vector<pair<int,int>> adj[], int V, int src, int dest[], int n){
    vector<bool> finalised(V, false);
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    int f = 0;
    while(f<V){
        int u = getMin(dist, finalised);
        // cout<<u<<":"<<endl; 
        finalised[u] = true;
        f++;

        for(auto p: adj[u]){
            int v = p.first;
            int w = p.second;
            if(!finalised[v] && dist[u]!=INT_MAX && dist[v]>(dist[u]+w)){
                dist[v] = dist[u]+w;
            }
        }
    }
    vector<int> v;
    // printVector(dist);
    for(int i=0;i<n;i++){
        v.push_back(dist[dest[i]]);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=0;i<(n-1);i++)
        ans += 2*v[i];
    
    return (ans+v[n-1]);


}


void solve() {
    int V, E;
    cin>>V>>E;
    vector<pair<int,int>> adj[V];
    for(int i=0;i<E;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u-1].push_back(make_pair(v-1, w));
        adj[v-1].push_back(make_pair(u-1, w));
    }
    int s, n;
    cin>>s>>n;
    int dest[n];
    cinArray(dest, n);
    cout<<dijkstra(adj, V, s-1, dest, n)<<endl;
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