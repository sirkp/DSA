// DoubleNode

class DoubleNode{
public:
    int data;
    DoubleNode* next;
    DoubleNode* prev;

    DoubleNode(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};