// https://practice.geeksforgeeks.org/contest-problem/minimum-at-pop0123593301262951/1/
stack<int>_push(int arr[],int n){
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++)
        s.push(min(s.top(), arr[i]));
    return s;
}

void _getMinAtPop(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}