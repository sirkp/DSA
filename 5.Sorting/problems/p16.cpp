// https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1/?track=SPCF-Sorting&batchId=154
bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.first!=p2.first)
        return (p1.first<p2.first);
    else
        return (p1.second<p2.second);    
}

void sortABS(int arr[],int n, int k){
    vector<pair<int, int>> v;

    for(int i=0;i<n;i++)
        v.push_back(make_pair(abs(arr[i]-k), i));

    sort(v.begin(), v.end(), compare);

    int temp[n];
    for(int i=0;i<n;i++)
    temp[i] = arr[v[i].second];
    
    for(int i=0;i<n;i++)
    arr[i] = temp[i];

}
