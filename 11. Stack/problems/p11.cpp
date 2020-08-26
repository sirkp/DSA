// https://practice.geeksforgeeks.org/problems/get-min-at-pop/1/?track=SPC-Stack&batchId=154
stack<int>_push(int arr[],int n){
    stack<int> s;
    int m = INT_MAX;
    for(int i=0;i<n;i++){
        m = min(m, arr[i]);
        s.push(m);
    }
    return s;
}

void _getMinAtPop(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}