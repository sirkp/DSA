// MinHeap
class MinHeap{
private:
    int *arr;
    int size, capacity;    
public:
    MinHeap(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    int left(int i){
        if(i>=0 && ((2*i)+1)<size)
            return ((2*i)+1);
        else
            return -1;
    }
    
    int right(int i){
        if(i>=0 && ((2*i)+2)<size)
            return ((2*i)+2);
        else
            return -1;
    }

    int parent(int i){
        if(i>0 && i<size )
            return ((i-1)/2);
        else
            return -1;
    }

    bool isFull(){
        return (size>=capacity);
    }
    
    bool empty(){
        return (size == 0);
    }

    void print(){
        printArray(arr, size);
    }

    int top(){
        if(!empty())
            return arr[0];
        else 
            return -1;
    }
    
    int getSize(){
        return size;
    }

    void setArr(int a[], int n){
        if(n<=capacity){
            for(int i=0;i<n;i++)
                arr[i] = a[i];
            size = n;
        }
    }

    void reverseHeapify(int i){// O(log(n))
        if(i>=0 && i<size){
            int p = parent(i);
            while(p!=-1 && arr[i]<arr[p]){
                swap(arr[p], arr[i]);
                i = p;
                p = parent(i);
            }
        }
    }

    void push(int x){// O(log(n))
        if(!isFull()){
            arr[size++] = x;
            reverseHeapify(size-1);
        }
    }

    void pop(){// O(log(n))
        if(!empty()){
            swap(arr[0], arr[size-1]);
            size--;
            heapify(0);
        }
    }

    void heapify(int parentIndex){// Time: O(log(n)), extra_space:O(1)
        if(parentIndex>=0 && parentIndex<size){
            int leftChildIndex, rightChildIndex, smallestElementIndex;
            while(parentIndex<size && parentIndex>=0){
                leftChildIndex = left(parentIndex);
                rightChildIndex = right(parentIndex);

                smallestElementIndex = parentIndex;

                if(leftChildIndex!=-1 && arr[leftChildIndex]<arr[smallestElementIndex])
                    smallestElementIndex = leftChildIndex;

                if(rightChildIndex!=-1 && arr[rightChildIndex]<arr[smallestElementIndex])
                    smallestElementIndex = rightChildIndex;

                if(smallestElementIndex!=parentIndex){
                    swap(arr[smallestElementIndex], arr[parentIndex]);
                    parentIndex = smallestElementIndex;
                }else
                    break;
            }
        }

    }

    int extract(){// O(log(n))
        if(!empty()){
            int t = top();
            pop();
            return t;
        }else
            return -1;
    }

    void decreaseKey(int i, int x){//O(log(n))
        if(i>=0 && i<size){
            arr[i] = x;
            reverseHeapify(i);
        }
    }

    void deleteAt(int i){// O(log(n))
        if(i>=0 && i<size){
            decreaseKey(i, INT_MIN);
            swap(arr[0], arr[size-1]);
            size--;
            heapify(0);
        }
    }

    void buildMinHeap(){// O(n)
        for(int i=((size/2)-1);i>=0;i--){
            heapify(i);
        }
    }
};


void pushTest(){
    MinHeap heap(12);
    heap.push(50);
    heap.print();
    heap.push(20);
    heap.print();
    heap.push(10);
    heap.print();
    heap.push(15);
    heap.print();
    heap.push(12);
    heap.print();
    heap.push(45);
    heap.print();
    heap.push(100);
    heap.print();
    heap.push(40);
    heap.print();
    heap.push(25);
    heap.print();
}

void popAndExtractTest(){
    MinHeap heap(20);
    int a[] = {20, 25, 30, 35, 40, 80, 32, 100, 70, 60};
    heap.setArr(a, (sizeof(a)/sizeof(a[0])));
    heap.print();
    cout<<heap.extract()<<endl;
    heap.print();
}

void heapifyTest(){
    MinHeap heap(6);
    int a[] = {10, 5, 12, 7, 8};
    heap.setArr(a, 5);
    heap.print();
    heap.heapify(0);
    heap.print();
}

void DecreaseKeyTest(){
    MinHeap heap(20);
    int a[] = {20, 80, 200, 90, 100, 250, 500, 120};
    heap.setArr(a, (sizeof(a)/sizeof(a[0])));
    heap.print();
    heap.decreaseKey(3, 10);
    heap.print();
}

void deleteTest(){
    MinHeap heap(20);
    int a[] = {10, 20, 30, 40, 50, 35, 38, 45};
    heap.setArr(a, (sizeof(a)/sizeof(a[0])));
    heap.print();
    heap.deleteAt(1);
    heap.print();
}

void buildHeapTest(){
    MinHeap heap(20);
    int a[] = {10, 5, 20, 2, 4, 8};
    heap.setArr(a, (sizeof(a)/sizeof(a[0])));
    heap.print();
    heap.buildMinHeap();
    heap.print();
}
