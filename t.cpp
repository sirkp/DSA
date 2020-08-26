#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    int leftCount;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        leftCount = 0;
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

Node* insert(Node* node, int key){
    if(node!=NULL){
        if(node->data==key)
            return node;
        else if(key>node->data){
            Node* right = insert(node->right, key);
            node->right = right;
        }
        else{
            Node* left = insert(node->left, key);
            node->left = left;
            node->leftCount++;
        }
        return node;
    }else{
        return new Node(key);
    }  
}

Node* getMax(Node* node){
    if(node!=NULL){
        if(node->right==NULL)
            return node;
        else
            return getMax(node->right);
    }else
        return NULL;
}

Node* deleteNode(Node* node,  int x){
    if(node!=NULL){
        if(node->data==x){
            if(node->left==NULL && node->right==NULL){
                delete node;
                node = NULL;
            }
            else if(node->left==NULL || node->right==NULL){
                Node* temp;
                if(node->left!=NULL)
                    temp = node->left;
                else
                    temp = node->right;
                delete node;
                node = temp;
            }else{
                Node* temp = new Node(getMax(node->left)->data);
                node = deleteNode(node, temp->data);
                temp->left = node->left;
                temp->right = node->right;
                delete node;
                node = temp;
            }
        }else if(x<node->data){
            Node* l = deleteNode(node->left, x);
            node->left = l;
            node->leftCount--;
        }else{
            Node* r = deleteNode(node->right, x);
            node->right = r;
        }
        return node;
    }else
        return NULL;
}

void inorder(Node* node){
    if(node){
        inorder(node->left);
        cout<<node->data<<": "<<node->leftCount<<endl;
        inorder(node->right);
    }
}

int kthElement(Node* node, int k, int prev=0){
    if(node){
        if(k==(prev+node->leftCount+1)){
            return node->data;
        }else if(k<(prev+node->leftCount+1)){
            return kthElement(node->left, k, prev);
        }else{
            return kthElement(node->right, k, (prev+node->leftCount+1));
        }
    }else
        return -1;

}

int kthElement(Node* node, int k){
    if(node){
        if(k==(node->leftCount+1)){
            return node->data;
        }else if(k<(node->leftCount+1)){
            return kthElement(node->left, k);
        }else{
            return kthElement(node->right, (k-(node->leftCount+1)));
        }
    }else
        return -1;
}

void solve() {
    int n;
    cin>>n;
    int arr[n];
    cinArray(arr, n);

    Node* root = NULL;
    for(int i=0;i<n;i++)
        root = insert(root, arr[i]);
    // inorder(root);
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<kthElement(root, i)<<endl;
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