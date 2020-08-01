// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/?track=SPCF-Sorting&batchId=154
int getMinutes(int time){
    return (((time/100)*60)+(time%100));
}

void sortTime(int arr[], int dep[], int n){
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++)
        v.push_back(make_pair(arr[i], i));
    
    sort(v.begin(), v.end());    
    
    for(int i=0;i<n;i++)
        arr[i] = v[i].first;

    for(int i=0;i<n;i++)
        v[i].first = dep[v[i].second];

    for(int i=0;i<n;i++)
        dep[i] = v[i].first;

}

int findPlatformMethod1(int arr[], int dep[], int n){// Hashing Method
    int N = 24*60;
    int hash[N] = {0};

    for(int i=0;i<n;i++){
        hash[getMinutes(arr[i])]++;
        hash[(getMinutes(dep[i])+1)]--;
    }

    for(int i=1;i<N;i++)
        hash[i] += hash[(i-1)];

    int platforms = *(max_element(hash, hash+N));
    return platforms;
}

int findPlatformMethod2(int arr[], int dep[], int n){// minHeap method
    sortTime(arr, dep, n);
    priority_queue<int, vector<int>, greater<int>> q;
    int platforms = 0;
    for(int i=0;i<n;i++){
        while(((int)q.size()>0) && (arr[i]>q.top())){
            q.pop();
        }
        q.push(dep[i]);
        platforms = max(platforms, (int)q.size());
    }
    return platforms;
}
