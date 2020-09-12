// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
bool isSafe(int ind, int c, int V, bool graph[101][101], vector<int> colors){
    bool safe = true;
    for(int i=0;i<V;i++){
        if(graph[ind][i] && colors[i]==c)
            return false;
    }
    return true;
}

void util(int index, int m, int V, bool graph[101][101], vector<int> colors, bool& ans){
    if(index==V){
        ans = true;
        return;
    }

    for(int i=0;i<m;i++){
        if(isSafe(index, i, V, graph, colors)){
            colors[index] = i;
            util(index+1, m, V, graph, colors, ans);
        }
        if(ans)
            return;
    }
}

bool graphColoring(bool graph[101][101], int m, int V) {
    vector<int> colors(V, -1);
    bool ans;
    util(0, m, V, graph, colors, ans);
    return ans;
}
