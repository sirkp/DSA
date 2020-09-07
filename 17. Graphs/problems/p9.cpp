// https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1/?track=DSASP-Graph&batchId=154
int Graph::levels(int level, int tar) {
    bool visited[V] = {false};
    queue<int> q;

    q.push(0);
    q.push(-1);
    visited[0] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v==-1){
            level++;
            if(q.size()>0)
                q.push(-1);
        }else{
            if(v==tar){
                return level;
            }
            for(auto x: adj[v]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
    return -1;
}