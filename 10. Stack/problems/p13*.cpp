// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/?track=SPC-Stack&batchId=154
// logic is based on nearest previous greater element, same method
// can be used to find next greater element(both this and below method)
vector <int> calculateSpan(int arr[], int n){// more effecient without stack
    vector<int> v(n, 1);
    int prev = 0;
    for(int i=1;i<n;i++){
        prev = i-1;
        while(arr[i]>=arr[prev] && prev>=0){
            v[i] += v[prev];
            prev -= v[prev];
        }
    }
    return v;
}

vector <int> calculateSpan(int arr[], int n){// stack method
    vector<int> v(n, 0);
    stack<int> s;
    s.push(0);
    v[0] = 1;
    for(int i=1;i<n;i++){
        while( !s.empty() && !(arr[s.top()]>arr[i])){
            s.pop();
        }
        v[i] = (s.empty())?(i+1):(i-s.top());
        s.push(i);
    }
    return v;
}
