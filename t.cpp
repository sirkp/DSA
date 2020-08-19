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

pair<int, int> util(Node* node){
    if(node!=NULL){
        pair<int, int> l = util(node->left);
        pair<int, int> r = util(node->right);
        
        return make_pair((l.second+r.second+node->data), (max(l.first, l.second)+max(r.first,r.second)));

    }else
        return make_pair(0, 0);
}

int getMaxSum(Node *root) {
    pair<int, int> p = util(root);
    return max(p.first, p.second);
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> v;
    cinVector(v, n);
    Node* root = deSerialize(v);
    inOrder(root);
    cout<<printKDistantfromLeaf(root, k)<<endl;
}


void test(){
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