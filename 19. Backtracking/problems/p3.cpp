// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1/?track=DSASP-Backtracking&batchId=154
void util(int l, int sum, int tar, vector<int> arr, vector<int> v, vector<vector<int>>& ans){
    if(sum==tar){
        ans.push_back(v);
    }else if(sum<tar){
        v.push_back(-1);
        for(int i=l;i<(int)arr.size();i++){
            v[(int)v.size()-1] = arr[i];
            sum += arr[i];
            util(i, sum, tar, arr, v, ans);
            sum -= arr[i];
        }
    }
}

vector<int> removeDuplicates(vector<int> v){
    unordered_set<int> hash;
    for(int i=0;i<(int)v.size();i++)
        hash.insert(v[i]);

    vector<int> uniq;
    for(auto x: hash)
        uniq.push_back(x);
    return uniq;
}

vector<vector<int> > combinationSum(vector<int> &arr, int tar) {
    vector<int> uniq = removeDuplicates(arr);
    sort(uniq.begin(), uniq.end());
    vector<int> v;
    vector<vector<int>> ans;
    util(0, 0, tar, uniq, v, ans);
    return ans;
}
