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

int util(Node* node, int &i, int k){
    if(node){
        int l = util(node->left, i, k);

        if(l!=-1)
            return l;

        if(i==k){
            return node->data;
        }
        i++;

        int r = util(node->right, i, k);
        return r;

    }else
        return -1;
}

int KthSmallestElement(Node* node, int k){
    int i = 1;
    return util(node, i, k);
}



void solve() {
    int n, k;
    cin>>n>>k;
    int arr[n];
    cinArray(arr, n);
    int i = median(arr, n)<<endl;
}


void test(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
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
        // test();
        testCase();
}