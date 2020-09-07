//Adjacency List
void adjacencyListInsert(vector<int> arr[], int u, int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void printAdjacencyList(vector<int> arr[], int n){
    for(int i=0;i<n;i++){
        cout<<i<<":";
        printVector(arr[i]);
    }
}


void adjacencyListInsert(list<int> arr[], int u, int v){
    arr[u].push_back(v);
    arr[v].push_back(u);
}

void printAdjacencyList(list<int> arr[], int n){
    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(auto x: arr[i])
            cout<<x<<" ";
        cout<<endl;
    }
}


void test() {
    vector<int> arr[4];
    adjacencyListInsert(arr, 0, 1);
    adjacencyListInsert(arr, 0, 2);
    adjacencyListInsert(arr, 1, 2);
    adjacencyListInsert(arr, 1, 3);
    printAdjacencyList(arr, 5);

}