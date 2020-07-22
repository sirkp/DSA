// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1/?track=SPCF-Hashing&batchId=154
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second>b.second)
        return true;
    else if(a.second<b.second)
        return false;
    else
        return (a.first<b.first);
}

vector<int> sortByFreq(int arr[],int n){
    unordered_map<int, int> hash;

    for(int i=0;i<n;i++)
        if(hash.find(arr[i])==hash.end())
            hash[arr[i]] = 1;
        else     
            hash[arr[i]]++;

    vector<pair<int, int>> temp;
    for(auto x: hash)
        temp.push_back(x);

    sort(temp.begin(), temp.end(), compare);  

    vector<int> v;

    for(int i=0;i<temp.size();i++){
        int j = 0;
        while(j<temp[i].second){
            v.push_back(temp[i].first);
            j++;
        }
    } 
    return v;
}
