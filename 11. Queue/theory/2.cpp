// Queue implementation using circular linked list
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
private:
    Node* tail;
public:
    Queue(){
        tail = NULL;
    }

    bool isEmpty(){
        if(tail==NULL)
            return true;
        else
            return false;
    }

    void enqueue(int x){
        if(isEmpty()){
            tail = new Node(x);
            tail->next = tail;
        }else{
            Node* temp = tail->next;
            tail->next = new Node(x);
            tail = tail->next;
            tail->next = temp;
        }
    }

    int dequeue(){
        if(!isEmpty()){
            Node* temp = tail->next;
            if(tail==tail->next){
                tail = NULL;
            }else{
                tail->next = tail->next->next;
            }
            int tempData = temp->data;
            temp = NULL;
            return tempData;
        }else  
            return -1;
    }

    int front(){
        if(!isEmpty())
            return tail->next->data;
        else
            return -1;
    }

    int rear(){
        if(!isEmpty())
            return tail->data;
        else
            return -1;
    }
};


void test(){
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<queue.front()<<" "<<queue.rear()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.front()<<" "<<queue.rear()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.front()<<" "<<queue.rear()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.front()<<" "<<queue.rear()<<endl;
}