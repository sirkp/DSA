// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1/?track=DSASP-Greedy&batchId=154
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second!=b.second){
        return (a.second<b.second);
    }else{
        return (a.first<b.first);
    }
}

int activitySelection(int start[], int end[], int n){
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(start[i], end[i]));
    }
    sort(v.begin(), v.end(), compare);

    int t = 0;
    int c = 0;
    for(int i=0;i<n;i++){
        if(v[i].first>=t){
            c++;
            t = v[i].second;
        }
    }
    
    return c;
}
