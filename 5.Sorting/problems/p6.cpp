// https://practice.geeksforgeeks.org/problems/heap-sort/1
void heapify(int arr[], int n, int parent)  {
    int largest = parent;
    int leftChild = (2*parent)+1;
    int rightChild = (2*parent)+2;
    
    if((leftChild<n) && (arr[leftChild] > arr[largest]))
        largest = leftChild;
    
    if((rightChild<n) && (arr[rightChild]>arr[largest]))
        largest = rightChild;
    
    if(largest!=parent){
        swap(arr[largest], arr[parent]);
        heapify(arr, n, largest);
    }    
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for(int i=((n/2)-1);i>=0;i--)
        heapify(arr, n, i);
}