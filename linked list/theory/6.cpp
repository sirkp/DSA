// Dynamic list
class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List{
private:
    Node* head;
    Node* tail;
    int s;
public:
    List(){
        this->s = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void displayList(){
        Node* node = head;
        while(node!=NULL){
            cout<<node->data<<" ";
            node = node->next;
        }
        cout<<endl;
    }

    int front(){
        if(head==NULL)
            return 0;
        else    
            return head->data;
    }

    int back(){
        if(tail==NULL)
            return 0;
        else
            return tail->data;
    }

    void push_front(int key){
        if(head==NULL){
            head = new Node(key);
            tail = head;
        }else{
            head->prev = new Node(key);
            head->prev->next = head;
            head = head->prev;
        }
        s++;
    }

    void push_back(int key){
        if(head==NULL){
            head = new Node(key);
            tail = head;
        }else{
            tail->next = new Node(key);
            tail->next->prev = tail;
            tail = tail->next;
        }
        s++;
    }

    void pop_back(){
        if(head!=NULL){
            if(head==tail){
                delete head;
                head = NULL;
                tail = NULL;
            }else{
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            s--;
        }
    }

    void pop_front(){
        if(head!=NULL){
            if(head==tail){
                delete head;
                head = NULL;
                tail = NULL;
            }else{
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            s--;
        }
    }

    int size(){
        return s;
    }
};
