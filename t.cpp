#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000

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

void cinMatrix(int arr[][100], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
}

void printMatrix(int arr[SIZE][SIZE], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int findMinOpeartion(int arr[][100], int n){
    int row = 0;
    for(int i=0;i<n;i++){
        int r = 0;
        for(int j=0;j<n;j++){
            r += arr[i][j];
        }
        row = max(row, r);
    }
    
    int col = 0;
    for(int j=0;j<n;j++){
        int c = 0;
        for(int i=0;i<n;i++){
            c += arr[i][j];
        }
        col = max(col, c);
    }
    // cout<<"row:"<<row<<" col:"<<col<<endl;
    int step = 0;
    if(row>col){
        for(int i=0;i<n;i++){
            int r = 0;
            for(int j=0;j<n;j++){
                r += arr[i][j];
            }
            // cout<<"row: "<<i<<" ->"<<(row-r)<<endl;
            step += (row-r);
        }
    }else{
        for(int j=0;j<n;j++){
            int c = 0;
            for(int i=0;i<n;i++){
                c += arr[i][j];
            }
            // cout<<"col: "<<j<<" ->"<<(col-c)<<endl;
            step += (col-c);
        }   
    }   
    return step;
    
}



void test(){
}


void solve(){

    int n;
    cin>>n;
    
    int arr[n][100];
    cinMatrix(arr, n);
    cout<<findMinOpeartion(arr, n)<<endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        // test();
        int t = 1;
        cin>>t;
        while(t--){
            solve();
        }
}