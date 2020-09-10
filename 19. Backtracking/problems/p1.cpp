// https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps-1587115621/1/?track=DSASP-Backtracking&batchId=154
// bad question, question mentions minimum no of jumps, but do not implement it
void util(int x, int y, vector<int> maze[], int N, vector<int> v, vector<int>& ans, bool& stop){
    if(x==(N-1) && y==(N-1)){
        ans = v;
        stop = true;
        return;
    }

    if(x>=0 && y>=0 && x<N && y<N && maze[x][y]!=0){
        int n = maze[x][y];
        v.push_back(-1);

        for(int i=1;i<=n;i++){
            v[(int)v.size()-1] = y+i;
            util(x, y+i, maze, N, v, ans, stop);
            if(stop)
                return;
            v[(int)v.size()-1] = (x+i)*(-1);
            util(x+i, y, maze, N, v, ans, stop);
            if(stop)
                return;
        }
    }
}

void solve(int N, vector<int> maze[]) {
    vector<int> v;
    vector<int> ans;
    bool stop = false;
    util(0, 0, maze, N, v, ans, stop);


    if(!stop)
        cout<<-1<<endl;
    else{
        vector<int> arr[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                arr[i].push_back(0);
        }
        
        int x=0, y=0;
        arr[x][y] = 1;
        for(int i=0;i<(int)ans.size();i++){
            if(ans[i]>0){
                y = ans[i];
            }else{
                x = abs(ans[i]);
            }
            arr[x][y] = 1;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }



    
}
