// Methods to pass 2 D array
// vector methods areless cache friendly than array bcoz only elements
// belonging to same row are stored at contigous location
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(n) for(int i=0;i<n;i++)
#define trav(i, j, n) for(i=j;i<n;i++)
#define debug(x) cerr<< #x <<": "<<x<<endl;

class Method1{// double pointer(pointer to array of pointer)
public:
    void printMatrix(int **arr, int m, int n){
        loop(m){
            int j;
            trav(j, 0, n){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    int** cinMatrix(int m, int n){
        int **arr;
        arr = new int *[m];
        loop(m){
            arr[i] = new int[n];
            int j;
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        return arr;
    }

    void invoke(){
        int m, n;
        cin>>m>>n;
        int** arr = cinMatrix(m, n);
        printMatrix(arr, m, n);
    }
};

class Method2{// array of pointer, prefer this(bcoz similar to 1 D array)
public:
    void printMatrix(int *arr[], int m, int n){
        loop(m){
            int j;
            trav(j, 0, n){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void cinMatrix(int* arr[], int m, int n){
        loop(m){
            arr[i] = new int[n];
            int j;
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
    }   

    void invoke(){
        int m, n;
        cin>>m>>n;
        int *arr[m];
        cinMatrix(arr, m, n);
        printMatrix(arr, m, n);
    }
};

class Method3{// array, passsed as single pointer by typecasting
public:
    int getElement(int *arr, int i, int j, int n){
        return (*((arr+i*n) + j));
    }

    void printMatrix(int *arr, int m, int n){
        int i, j; 
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++) 
                cout<<getElement(arr, i, j, n)<<" "; 
            cout<<endl;
        } 

    }
    void invoke(){
        int m, n;
        cin>>m>>n;
        int arr[m][n];
        loop(m){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        printMatrix((int *)arr, m, n);
    }
};

class Method4{// vector array
public:
    void printMatrix(vector<int> arr[], int m){
        int n = arr[0].size();
        loop(m){
            int j;
            trav(j, 0, n){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    void invoke(){
        int temp;
        int m, n;
        cin>>m>>n;
        vector<int> arr[m];
        loop(m){
            int j;
            for(int j=0;j<n;j++){
                cin>>temp;
                arr[i].push_back(temp);
            }
        }
        printMatrix(arr, m);
    }
};

class Method5{// vector of vector
public:
    void printMatrix(vector<vector<int>> arr){
        int m = arr.size();
        int n = arr[0].size();
        loop(m){
            int j;
            trav(j, 0, n){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    void invoke(){
        int temp;
        int m, n;
        cin>>m>>n;
        vector<vector<int>> arr;
        loop(m){
            int j;
            vector<int> v;
            for(int j=0;j<n;j++){
                cin>>temp;
                v.push_back(temp);
            }
            arr.push_back(v);
        }
        printMatrix(arr);
    }
};

void test(){// uncomment 1 at a time
    // Method1 obj;
    Method2 obj;
    // Method3 obj;
    // Method4 obj;
    // Method5 obj;
    obj.invoke();
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        test();
}