// stack implementation linked list
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
private:
    Node* head;
public:
    Stack(){
        head = NULL;
    }
 
    void push(int key){
        Node* temp = new Node(key);
        temp->next = head;
        head = temp;
    }

    void pop(){
        if(head!=NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int peek(){
        if(head!=NULL)
            return head->data;
        else
            return -1;
    }
    
    bool isEmpty(){
        if(head==NULL)
            return true;
        else
            return false;
    }
};
