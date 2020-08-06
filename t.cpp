#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void printArray(int arr[], int n, string s=""){
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;    
}

void cinArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }    
}

void cinVector(vector<int>& v, int n){
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v.push_back(temp);
    }    
}

void printVector(vector<int> v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

vector<int> nextSmallerElement(int arr[], int n){// without stack
    vector<int> v(n, 1);
    int next;
    for(int i=(n-1);i>=0;i--){
        next = i+1;
        while(next<n && arr[i]<=arr[next]){
            v[i] += v[next];
            next += v[next];
        }
    }
    // printVector(v);
    for(int i=0;i<n;i++){
        v[i] = i+v[i];
    }
    return v;
}

vector<int> prevSmallerElement(int arr[], int n){
    vector<int> v(n, 1);
    int prev;
    for(int i=1;i<n;i++){
        prev = i-1;
        while(arr[i]<=arr[prev] && prev>=0){
            v[i] += v[prev];
            prev -= v[prev];
        }
    }
    // printVector(v);
    for(int i=0;i<n;i++){
        v[i] = i-v[i];
    }
    return v;
}

vector<int> printMaxOfMin(int arr[], int n){
    vector<int> left = prevSmallerElement(arr, n);
    // printVector(prev);
    vector<int> right = nextSmallerElement(arr, n);
    // printVector(next);

    vector<int> ans(n+1, 0);
    for(int i=0;i<n;i++)
        ans[right[i]-left[i]-1] = max(ans[right[i]-left[i]-1], arr[i]);

    // printVector(ans);
    for(int i=(n-1);i>=1;i--)
        ans[i] = max(ans[i], ans[i+1]);

    // printVector(ans);
    ans.erase(ans.begin());
    // printVector(ans);
    
    return ans;
}



void solve() {
    int n;
    cin>>n;
    int arr[n];
    cinArray(arr, n);
    vector<int> v = printMaxOfMin(arr, n);
    // cout<<v<<endl;
}


void test(){
    KStack s(6, 3);
    cout<<s.isEmpty(0)<<endl;
    cout<<s.isEmpty(1)<<endl;
    cout<<s.isEmpty(2)<<endl;
    cout<<s.isFull()<<endl;
    s.push(100, 0);
    s.push(200, 0);
    s.push(300, 0);
    s.push(400, 1);
    s.push(500, 1);
    s.push(600, 2);

    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    
}

void testCase(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        test();
        // testCase();
}