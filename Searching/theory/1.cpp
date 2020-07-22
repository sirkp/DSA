//my lowerBound function
int lower_bound(int arr[], int n, int x) { 
    int mid; 
    int low = 0; 
    int high = n-1; 
    while (low < high) { 
        mid = low + (high - low) / 2; 
        if (x <= arr[mid]) { 
            high = mid; 
        } 
        else { 
            low = mid + 1; 
        } 
    } 
    return low; 
}