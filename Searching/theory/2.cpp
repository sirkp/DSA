// UpperBound
int upper_bound(int arr[], int n, int x) 
{ 
    int mid; 
    int low = 0; 
    int high = n-1; 
    while (low < high) { 
        mid = (low + high) / 2; 
        if (x >= arr[mid]) { 
            low = mid + 1; 
        } 
        else { 
            high = mid; 
        } 
    } 
    return low; 
} 
