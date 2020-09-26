// queue implementation using circular array
class Queue{
private:
    int *arr;
    int capacity;
    int size, frontPtr, rearPtr;
public:
    Queue(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
        rearPtr = capacity-1;
        frontPtr = 0;
    }
    
    bool isFull(){
        if(size<capacity)
            return false;
        else
            return true;
    }

    bool isEmpty(){
        if(size==0)
            return true;
        else
            return false;
    }

    void enqueue(int x){
        if(!isFull()){
            rearPtr = (rearPtr+1)%capacity;
            arr[rearPtr] = x;  
            size++;
        }
    }

    int dequeue(){
        if(!isEmpty()){
            int temp = arr[frontPtr];
            frontPtr = (frontPtr+1)%capacity;
            size--;
            return temp;
        }else  
            return -1;
    }

    int front(){
        if(!isEmpty())
            return arr[frontPtr];
        else
            return -1;
    }

    int rear(){
        if(!isEmpty())
            return arr[rearPtr];
        else
            return -1;
    }
};

void test() {
    Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<queue.front()<<" "<<queue.rear()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    queue.enqueue(4);
    queue.enqueue(5);
    cout<<queue.front()<<" "<<queue.rear()<<endl;
    queue.enqueue(6);
    queue.enqueue(7);
    cout<<queue.isFull()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.isEmpty()<<endl;
}
