// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/?track=DSASP-Heap&batchId=154
#define N 105

typedef pair<int, int> pi;

int *mergeKArrays(int arr[][N], int k){
    int index[k] = {0};
    int *sortedArr = new int[k*k];
    int i = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i=0;i<k;i++)
        pq.push(make_pair(arr[i][0], i));

    while(!pq.empty()){
        pi p = pq.top();
        pq.pop();
        sortedArr[i] = p.first;
        index[p.second]++;
        if(index[p.second]<k)
            pq.push(make_pair(arr[p.second][index[p.second]], p.second));
        i++;
    }
    return sortedArr;
}
