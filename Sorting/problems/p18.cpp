// https://practice.geeksforgeeks.org/problems/kth-smallest-element5545-1587115620/1/?track=SPCF-Sorting&batchId=154
// Method 1
void maxHeapify(int arr[], int n, int parentIndex){
    int leftChildIndex = 2*parentIndex+1;
    int rightChildIndex = 2*parentIndex+2;
    int largestNodeIndex = parentIndex;

    if(leftChildIndex<n && arr[leftChildIndex]>arr[largestNodeIndex])
        largestNodeIndex = leftChildIndex;

    if(rightChildIndex<n && arr[rightChildIndex]>arr[largestNodeIndex])
        largestNodeIndex = rightChildIndex;

    if(parentIndex!=largestNodeIndex){
        swap(arr[parentIndex], arr[largestNodeIndex]);
        maxHeapify(arr, n, largestNodeIndex);
    }    
}

int maxHeapMethod(int arr[], int n, int k){
    for(int i = k/2-1;i>=0;i--)
        maxHeapify(arr, k, i);

    for(int i=k;i<n;i++)
        if(arr[i]<arr[0]){
            arr[0] = arr[i];
            maxHeapify(arr, k, 0);
        }

    return arr[0];    
}

// Method 2
void minHeapify(int arr[], int n, int parentIndex){
    int leftChildIndex = 2*parentIndex+1;
    int rightChildIndex = 2*parentIndex+2;
    int largestNodeIndex = parentIndex;

    if(leftChildIndex<n && arr[leftChildIndex]<arr[largestNodeIndex])
        largestNodeIndex = leftChildIndex;

    if(rightChildIndex<n && arr[rightChildIndex]<arr[largestNodeIndex])
        largestNodeIndex = rightChildIndex;

    if(largestNodeIndex!=parentIndex){
        swap(arr[largestNodeIndex], arr[parentIndex]);
        minHeapify(arr, n, largestNodeIndex);
    }    
}

void buildMinHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)
        minHeapify(arr, n, i);
}

int minHeapMethod(int arr[], int n, int k){
    buildMinHeap(arr, n);

    for(int i=n-1;i>n-k;i--){
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
    return arr[0];
}

// Method 3
int partition(int arr[], int low, int high){
    int j = low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<=arr[high]){
            j++;
            swap(arr[j], arr[i]);
        }
    }
    j++;
    swap(arr[j], arr[high]);
    return j;
}

int randomPartition(int arr[], int low, int high){
    srand(time(NULL));
    int randomIndex = low;
    if(high!=low)
        randomIndex = low + rand()%(high-low);
    swap(arr[high], arr[randomIndex]);
    return partition(arr, low, high);
}

// seems like O(n^2) but is O(n) bcoz very less chance that we will pick max or min element 
int quickSortMethod(int arr[], int low, int high, int k, int n){
    if(low<=high){
        int p = randomPartition(arr, low, high);
        if(p==(k-1))
            return arr[p];
        else if(p>(k-1))
            return quickSortMethod(arr, low, (p-1), k, n);
        else
            return quickSortMethod(arr, (p+1), high, k, n);
    }
    return -1;
}

int kthSmallest(int arr[], int n, int k){
    return maxHeapMethod(arr, n, k);
    return minHeapMethod(arr, n, k);
    return quickSortMethod(arr, 0, n-1, k, n);
}

