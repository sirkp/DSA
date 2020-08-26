// https://practice.geeksforgeeks.org/problems/operations-on-binary-min-heap/1/?track=DSASP-Heap&batchId=154
int MinHeap::extractMin() {
    if(heap_size>0){
        int t = harr[0];
        swap(harr[0], harr[heap_size-1]);
        heap_size--;
        if(heap_size>0)
            MinHeapify(0);
        return t;
    }else
        return -1;
    
}

void MinHeap::deleteKey(int i) {
    if(heap_size>0 && i>=0 && i<heap_size){
        decreaseKey(i, INT_MIN);
        swap(harr[0], harr[heap_size-1]);
        heap_size--;
        MinHeapify(0);
    }
}

void MinHeap::insertKey(int k) {
    if(heap_size>=0 && heap_size<capacity){
        harr[heap_size++] = k;
        
        int i = heap_size-1;
        int p = parent(i);
        while(harr[i]<harr[p]){
            swap(harr[p], harr[i]);
            i = p;
            p = parent(i);
        }
    }
}
