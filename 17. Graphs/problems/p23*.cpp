// https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1/?track=DSASP-Graph&batchId=154
void dfs(int u, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<bool>& stackMember, stack<int>& Stack){
    static int time = 0;
    visited[u] = true;
    
    disc[u] = low[u] = ++time;
    
    Stack.push(u);
    stackMember[u] = true;

    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v, adj, visited, disc, low, stackMember, Stack);
            low[u] = min(low[u], low[v]);
        }else if(stackMember[v])
            low[u] = min(low[u], disc[v]);
    }

    if(low[u]==disc[u]){
        while(Stack.top()!=u){
            cout<<Stack.top()<<" ";
            stackMember[Stack.top()] = false;
            Stack.pop();
        }
        cout<<Stack.top()<<",";
        stackMember[Stack.top()] = false;
        Stack.pop();
    }
}

void find(vector<int> adj[], int V) {
    vector<int> disc(V);
    vector<int> low(V);
    stack<int> Stack;
    vector<bool> visited(V, false);
    vector<bool> stackMember(V, false);
    for(int i=0;i<V;i++)
        if(!visited[i])
            dfs(i, adj, visited, disc, low, stackMember, Stack);
}
