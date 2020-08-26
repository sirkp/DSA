// dequeue implementation with circular doubly linked list
class Deque{
private:
    Node* tail;
    int size;
public:
    Deque(){
        tail = NULL;
        size = 0;
    }

    bool isEmpty(){
        return (size==0);
    }

    bool getSize(){
        return size;
    }

    void push_front(int x){
        if(tail==NULL){
            tail = new Node(x);
            tail->next = tail;
            tail->prev = tail;
        }else{
            Node* temp = tail->next;
            tail->next = new Node(x);
            tail->next->prev = tail;
            tail->next->next = temp;
            temp->prev = tail->next;
        }
        size++;
    }
    
    void push_back(int x){
        if(tail==NULL){
            tail = new Node(x);
            tail->next = tail;
            tail->prev = tail;
        }else{
            Node* temp = tail->next;
            tail->next = new Node(x);
            tail->next->prev = tail;
            tail->next->next = temp;
            temp->prev = tail->next;
            tail = tail->next;
        }
        size++;
    }

    void pop_back(){
        if(!isEmpty()){
            Node* temp = tail;
            if(tail->next==tail)
                tail = NULL;
            else{
                tail->prev->next = tail->next;
                tail->next->prev = tail->prev;
                tail = tail->prev;
                delete(temp); 
            }
        }
    }

    void pop_front(){
        if(!isEmpty()){
            Node* temp = tail->next;
            if(tail->next==tail)
                tail = NULL;
            else{
                tail->next = tail->next->next;
                tail->next->next->prev = tail;
                delete(temp);
            }
        }

    }

    int front(){
        if(!isEmpty())
            return tail->next->data;
        else
            return INT_MIN;
    }
    
    int back(){
        if(!isEmpty())
            return tail->data;
        else
            return INT_MIN;
    }

    void print(){
        if(tail==NULL)
            return;
        Node* node = tail->next;
        cout<<"deque:"<<node->data<<" ";
        node = node->next;
        while(node!=tail->next){
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<endl;

        cout<<"f:"<<front()<<" r:"<<back()<<endl;
        
    }
};

void test(){
    Deque dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.push_back(6);
    dq.push_back(7);
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
