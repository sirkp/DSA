
bool compare(Job a, Job b){
    return (a.profit>b.profit);
}

int getMaxIndex(int j, bool occupied[]){
    for(int i=j;i>=0;i--){
        if(!occupied[i]){
            occupied[i] = true;
            return i;
        }
    }
    return -1;
}

pair<int,int> JobScheduling(Job arr[], int n) { 
    sort(arr, arr+n, compare);
    int T = 0;
    for(int i=0;i<n;i++){
        T = max(T, arr[i].dead);
    }

    bool occupied[T] = {false};
    int no = 0, profit = 0;
    for(int i=0;i<n;i++){
        int ind = getMaxIndex(arr[i].dead-1, occupied);
        if(ind!=-1){
            no++;
            profit += arr[i].profit;
        }
    }
    return make_pair(no, profit);
} 
