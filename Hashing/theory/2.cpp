// hashing with open addressing

#include<bits/stdc++.h>
using namespace std;
class Hash{// -1: empty, 0: deleted
private:
    int m;// or bucket
    int *table;
public:
    Hash(int m){
        this->m = m;
        table = new int[m];
        for(int i=0;i<m;i++)
            table[i] = -1;
    }
    int hashFn(int key, int i){
        int h1 = key%m;
        int h2 = (m-1) - (key%(m-1));// double hashing
        // int h2 = 1;// linear probing
        // int h2 = i;// quadratic probrabing
        return ((h1 + (i*h2))%m);
    }

    int searchKey(int key){
        int i = 0;
        int index = hashFn(key, i);
        int first = index;
        while(table[index]!=key &&  table[index]!=-1 && (i==0 || index!=first)){
            i++;
            index = hashFn(key, i);
        }

        if(table[index]==key)
            return index;
        else
            return -1;    
    }

    void insertKey(int key){
        int i = 0;
        int index = hashFn(key, i);
        int first = index;
        while(table[index]>0 && (i==0 || index!=first)){
            i++;
            index = hashFn(key, i);
        }
        if(table[index]<=0)
            table[index] = key;
    }

    void deleteKey(int key){
        int index = searchKey(key);
        if(index!=-1)
            table[index] = 0;
    }
    void showHashTable(){
        for(int i=0;i<m;i++){
            cout<<i<<": "<<table[i]<<endl;  
        }
    }
};

void test(){
    int n = 7;
    int arr[n] = {49, 63, 56, 52, 54, 48, 35};

    Hash h(7);
    for(int i=0;i<n;i++)
        h.insertKey(arr[i]);

    h.showHashTable();

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" -> "<<h.searchKey(arr[i])<<endl;

    cout<<14<<" -> "<<h.searchKey(14)<<endl;

    h.deleteKey(35);    
    h.deleteKey(49);    
    h.showHashTable();
    cout<<63<<" -> "<<h.searchKey(63)<<endl;
    h.insertKey(8);
    h.showHashTable();
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        test();
}
