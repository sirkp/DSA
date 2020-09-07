// BFS
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1/
// O(V+E), space: O(V)
// Time:E comes for traversing all adjacency list element, V comes for when all vertices are disconnected
// space: V for maintaing visited array
vector<int> bfs(vector<int> g[], int n){
    vector<int> v;
    queue<int> q;
    bool visited[n] = {false};
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        v.push_back(q.front());
        for(auto x: g[q.front()])
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        q.pop();
    }
    return v;
}