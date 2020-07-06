#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

void prepare(int arr[SIZE][SIZE], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] *= 2; 
        }
    }
}

int getVal(int arr[SIZE][SIZE], int i, int j){
    return (arr[i][j]/2);    
}

int getRemainder(int arr[SIZE][SIZE], int i, int j){
    return (arr[i][j]%2);
}

void printNewMatrix(int arr[SIZE][SIZE], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<getRemainder(arr, i, j)<<" ";
        }
        cout<<endl;
    }
}


void changeColRow(int arr[SIZE][SIZE], int m, int n, int ii, int jj, int row[], int col[]){
    // cout<<"i:"<<ii<<" j:"<<jj<<" col[j]"<<col[jj]<<" -> ";
    if(row[ii]==0){   
        row[ii] = 1; 
        // cout<<" row:"<<ii;
        for(int j=0;j<n;j++){//row
            if(getRemainder(arr, ii, j)==0){
                arr[ii][j]++;
            }
        }
    }      
        // cout<<endl;  
}

void booleanMatrix(int m, int n, int arr[SIZE][SIZE]){
    int row[m] = {0};
    int col[n] = {0};
    prepare(arr, m, n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(getVal(arr, i, j)==1){
                changeColRow(arr, m , n, i, j, row, col);
            }
        }
    }
    printNewMatrix(arr, m, n);    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    
    while(t--){
        int arr[SIZE][SIZE];
        int m, n;
        cin>>m>>n;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            cin>>arr[i][j];
        
        booleanMatrix(m, n, arr);    
    }

}