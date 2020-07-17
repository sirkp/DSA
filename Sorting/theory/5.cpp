// https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
// QuickSort Tail Call Optimization
void quickSort(int arr[], int low, int high) 
{ 
    while (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
  
        low = pi+1; 
    } 
}