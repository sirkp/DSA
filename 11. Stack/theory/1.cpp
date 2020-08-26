// stack array implementation

#define SIZE 10
class Stack{
private:
    int arr[SIZE];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(int key){
        if(top==(SIZE-1)){
            cout<<"Stack is Full\n";
        }else{
            top++;
            arr[top] = key;
        }
    }
    
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }

    void pop(){
        if(!isEmpty()){
            arr[top] = -1;
            top--;
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        }else
            return -1;
    }
};
