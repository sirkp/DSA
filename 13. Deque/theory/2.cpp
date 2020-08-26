// deque implementation using array
class Deque{
private:
    int* arr;
    int ptr;
    int s;
    int capacity;
public:
    Deque(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        ptr = 1;
        s = 0;
    }

    bool empty(){
        return (s==0);
    }

    bool size(){
        return s;
    }

    bool full(){
        return (s==capacity);
    }

    void push_front(int x){
        if(!full()){
            ptr--;
            if(ptr<0)
                ptr = capacity-1;
            arr[ptr] = x;
            s++;
        }
    }
    
    void push_back(int x){
        if(!full()){
            arr[(ptr+s)%capacity] = x;
            s++;
        }
    }

    void pop_back(){
        if(!empty()){
            s--;
        }
    }

    void pop_front(){
        if(!empty()){
            ptr = (ptr+1)%capacity;
            s--;
        }
    }

    int front(){
        if(!empty())
            return arr[ptr];
        else
            return INT_MIN;
    }
    
    int back(){
        if(!empty())
            return arr[(ptr+s-1)%capacity];
        else
            return INT_MIN;
    }

    void print(){
        if(!empty()){
            int i = 0;
            int j = ptr;
            while(i<s){
                cout<<arr[j]<<" ";
                j = (j+1)%capacity;
                i++;
            }
            cout<<endl<<front()<<" "<<back()<<endl;
            cout<<endl;
        }
    }
};

void test(){
    Deque dq(7);
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.push_back(6);
    dq.push_back(7);
    dq.push_back(8);
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
    dq.print();
    dq.pop_back();
    dq.print();
    dq.pop_front();
}
