// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/?track=DSASP-Graph&batchId=154
int minStepToReachTarget(int knightPos[], int targetPos[], int n) {
    int sx = knightPos[0], sy = knightPos[1];
    int tx = targetPos[0], ty = targetPos[1];

    if(sx==tx && sy==ty)
        return 0;
    
    vector<bool> visited[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            visited[i].push_back(false);
    }
    int count = 1;
    queue<pair<int, int>> q;
    pair<int, int> null = make_pair(-1, -1);
    q.push(make_pair(sx, sy));
    q.push(null);

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        if(p==null){
            count++;
            if(q.size()>0)
                q.push(null);
        }else{
            int x = p.first, y=p.second;
            pair<int, int> pos[8] = {{x-2, y-1}, {x-2, y+1}, {x-1, y-2}, {x-1, y+2},
                                    {x+1, y-2}, {x+1, y+2}, {x+2, y-1}, {x+2, y+1}};
            
            for(int i=0;i<8;i++){
                if(pos[i].first==tx && pos[i].second==ty)
                    return count;

                if(pos[i].first>=0 && pos[i].first<n && pos[i].second>=0 && pos[i].second<n && !visited[pos[i].first][pos[i].second]){
                    visited[pos[i].first][pos[i].second] = true;
                    q.push(pos[i]);
                }
            }
        }
    }



    return -1;
}
