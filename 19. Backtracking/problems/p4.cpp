https://practice.geeksforgeeks.org/problems/subsets-1587115621/1/
void util(int l, int r, long long int no, vector<int>& arr, vector<int> v, unordered_set<long long int>& hash, vector<vector<int>>& ans){
    if(hash.find(no)==hash.end()){
        ans.push_back(v);
        hash.insert(no);
    }
    v.push_back(-1);
    for(int i=l;i<r;i++){
        v[v.size()-1] = arr[i];
        util(i+1, r, ((no*10)+arr[i]), arr, v, hash, ans);
    }
}

vector<vector<int>> AllSubsets(vector<int> arr, int n){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> v;
    unordered_set<long long int> hash;
    util(0, n, 0, arr, v, hash, ans);
    return ans;
}
