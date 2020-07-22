// hashing with chaining

#include<bits/stdc++.h>
using namespace std;

class Hash{
private:
    int m;// or bucket
    list<int> *table;
public:
    Hash(int m){
        this->m = m;
        table = new list<int>[m];
    }
    int hashFn(int key){
        return (key%m);
    }

    bool searchKey(int key){
        int index = hashFn(key);
        for(auto x: table[index]){
            if(x == key)
                return true;
        }
        return false;
    }

    void insertKey(int key){
        int index = hashFn(key);
        table[index].push_back(key);
    }

    void deleteKey(int key){
        int index = hashFn(key);
        for(list<int>::iterator i = table[index].begin();i!=table[index].end();i++){
            if((*i) == key){
                table[index].erase(i);
                break;
            }
        } 
    }
    void showHashTable(){
        for(int i=0;i<m;i++){
            cout<<i<<": ";
            for(auto x: table[i])
                cout<<x<<"->";
            cout<<endl;    
        }
    }
};

void searchUtil(Hash h, int key){
    cout<<key<<": ";
    if(h.searchKey(key))
        cout<<"Yes\n";
    else
        cout<<"No\n";    
}

void test(){
    int n = 10;
    int arr[n] = {50, 21, 58, 17, 15, 49, 56, 22, 23, 25};
    
    Hash h(7);

    for(int i=0;i<n;i++)
        h.insertKey(arr[i]);

    h.showHashTable();

    for(int i=0;i<n;i++)
        searchUtil(h, arr[i]);

    searchUtil(h, 7);

    h.deleteKey(7); 
    h.showHashTable();   
    h.deleteKey(21);    
    h.showHashTable();   
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    test();
}