#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n, string s=""){
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;    
}

void cinArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
    }    
}

void cinVector(vector<int>& v, int n){
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }    
}

void printVector(vector<int> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}


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

void solve() {
    int n, tar;
    cin>>n;
    vector<int> arr;
    cinVector(arr, n);
    cin>>tar;
    vector<vector<int>> ans = combinationSum(arr, tar);
    for(int i=0;i<(int)ans.size();i++){
        for(int j=0;j<(int)ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

}

void test(){
    vector<int> v;
    v.push_back(1);
    v.push_back(-3);
    v.push_back(3);
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(-3);
    ans.push_back(3);
}

void testCase(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        // test();
        testCase();
}