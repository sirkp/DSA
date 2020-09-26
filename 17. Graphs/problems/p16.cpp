// https://www.hackerrank.com/challenges/minimum-swaps-2/problem

// https://www.hackerrank.com/challenges/minimum-swaps-2/copy-from/177235047 
// gfg - very bad time limit, TLE although nlogn solution use DAT
int minimumSwaps(vector<int> arr){// hashing method
    int n = (int)arr.size();
    vector<int> v;
    unordered_map<int, int> hash;
    for(int i=0;i<n;i++){
        hash.insert(make_pair(arr[i], i));
        v.push_back(arr[i]);
    }
    
    sort(v.begin(), v.end());

    int c = 0;
    for(int i=0;i<n;i++){
        if(v[i]!=arr[i]){
            hash[arr[i]] = hash[v[i]];
            arr[hash[arr[i]]] = arr[i];
            c++;
        }
    }
    
    return c;
}


void dfs(int u, vector<int> adj[], bool visited[], int& count){
    visited[u] = true;
    count++;
    for(auto v: adj[u]){
        if(!visited[v])
            dfs(v, adj, visited, count);
    }
}

// gfg very bad, gives segementation fault although same code got accepted in hackerrank
int minimumSwaps(vector<int> arr){// graph method
    int n = (int)arr.size();
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end());
    vector<int> adj[n];



    for(int i=0;i<n;i++){
        adj[v[i].second].push_back(i);
    }
    // printGraph(adj, n);

    int ans = 0;
    bool visited[n] = {false};
    int count = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count = 0;
            dfs(i, adj, visited, count);
            ans += (count-1);
        }
    }
    
    return ans;
}

// works for duplicate also
int minSwaps(int arr[], int n){
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++)
        v.push_back(make_pair(arr[i], i));

    sort(v.begin(), v.end());
    vector<int> val;
    vector<int> ind;
    for(auto p: v)
        val.push_back(p.first), ind.push_back(p.second);

    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=val[i]){
            int index = lower_bound(val.begin()+1, val.end(), arr[i]) - val.begin();
            swap(arr[i], arr[ind[i]]);
            swap(ind[index], ind[i]);
            count++;
        }
    }       
    return count;
}