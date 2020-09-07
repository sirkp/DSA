
// https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1/
void printVector(vector<int> v, string s=""){
    int n = (int)v.size();
    for(int i=0;i<n;i++){
        cout<<"-> ";
        cout<<v[i];
    }    
    cout<<endl;    
}


void printGraph(vector<int> adj[], int n){
    for(int i=0;i<n;i++){
        cout<<i;
        printVector(adj[i]);
    }
    
}