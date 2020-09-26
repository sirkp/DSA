// Heap sort
// time:O(nlogn) extra_space: no
// not stable in this implementation, but can be made
void swap(int& a, int& b){
    if((&a)!=(&b)){
        a = a+b;
        b = a-b;
        a = a-b;
    }
}

void heapify(int arr[], int n, int parent){// O(logn)
    int largest = parent;
    int leftChild = (2*parent)+1;
    int rightChild = (2*parent)+2;
    
    if((leftChild<n) && (arr[leftChild]>arr[largest]))
        largest = leftChild;
    
    if((rightChild<n) && (arr[rightChild]>arr[largest]))
        largest = rightChild;

    if(largest!=parent){
        swap(arr[largest], arr[parent]);
        heapify(arr, n, largest);
    }   
}

void buildMaxHeap(int arr[], int n){// O(n)
    for(int i=((n/2)-1);i>=0;i--){
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    
    buildMaxHeap(arr, n);
    for(int i=(n-1);i>=0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
