// https://practice.geeksforgeeks.org/problems/most-occurring-elements-1587115620/1/
int kLargestSum(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    return sum;
}

int kMostFrequent(int arr[], int n, int k) { 
    unordered_map<int, int> hash;
    
    for(int i=0;i<n;i++)
        if(hash.find(arr[i])!=hash.end()){
            hash[arr[i]]++;
        }else
            hash[arr[i]] = 1;
    
    int m = (int)hash.size();
    int j = 0;
    int brr[m];
    for(auto x: hash){
        brr[j] = x.second;
        j++;
    }
    return kLargestSum(brr, m, k);
} 
