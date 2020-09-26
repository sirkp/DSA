// https://leetcode.com/problems/3sum/
vector<vector<int>> threeSum(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = (int)arr.size();
    vector<vector<int>> ans;
    int first, second;
    for(int i=0;i<(n-2);i++){
        if(i!=0 && arr[i]==arr[i-1])
            continue;
        
        first = INT_MAX, second = INT_MAX;
        int l = i+1, r = n-1;
        while(l<r){
            if((arr[i]+arr[l]+arr[r])>0)
                r--;
            else if((arr[i]+arr[l]+arr[r])<0)
                l++;
            else{
                if(first==INT_MAX && second==INT_MAX || arr[l]!=first || arr[r]!=second){
                    ans.push_back({arr[i], arr[l], arr[r]});
                    first = arr[l], second = arr[r];
                }
                r--;
                l++;
            }
        }
    }
    return ans;
}