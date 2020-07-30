#include<bits/stdc++.h>
using namespace std;




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

void printVector(vector<int>& v, string s=""){
    int n = (int)v.size();
    if(s!="")
        cout<<s<<": ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }    
    cout<<endl;    
}

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List{
private:
    Node* head;
    Node* tail;
    int s;
public:
    List(){
        this->s = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void displayList(){
        Node* node = head;
        while(node!=NULL){
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<endl;
    }

    int front(){
        if(head==NULL)
            return 0;
        else    
            return head->data;
    }

    int back(){
        if(tail==NULL)
            return 0;
        else
            return tail->data;
    }

    void push_front(int key){
        if(head==NULL){
            head = new Node(key);
            tail = head;
        }else{
            head->prev = new Node(key);
            head->prev->next = head;
            head = head->prev;
        }
        s++;
    }

    void push_back(int key){
        if(head==NULL){
            head = new Node(key);
            tail = head;
        }else{
            tail->next = new Node(key);
            tail->next->prev = tail;
            tail = tail->next;
        }
        s++;
    }

    void pop_back(){
        if(head!=NULL){
            if(head==tail){
                delete head;
                head = NULL;
                tail = NULL;
            }else{
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            s--;
        }
    }

    void pop_front(){
        if(head!=NULL){
            if(head==tail){
                delete head;
                head = NULL;
                tail = NULL;
            }else{
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            s--;
        }
    }

    int size(){
        return s;
    }
};

void solve(){
}


void test(){
    // list<int> l;
    // l.push_back(1);
    // cout<<l.front()<<endl;
    // cout<<l.back()<<endl;

    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(3);
    list.push_front(4);
    list.push_back(5);
    list.push_back(6);
    list.displayList();
    list.pop_back();
    list.pop_back();
    list.displayList();
    list.pop_front();
    list.pop_front();
    list.displayList();
    list.pop_front();
    list.displayList();
    list.pop_back();
    list.displayList();
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