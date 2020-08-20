// data structure that supports 1) Get Minimum, 2) Get Maximum, 3) Insert Minimum
// ,4) Insert Maximum, 5) Delete Minimum, 6) Delete Maximum
class SpecialDeque{
private:
    deque<int> dq;
public:

    bool isEmpty(){
        return dq.empty();
    }

    void push_min(int x){
        if(dq.empty() || x<dq.front())
            dq.push_front(x);
    }
    
    void push_max(int x){
        if(dq.empty() || x>dq.back())
            dq.push_back(x);
    }

    void pop_min(){
        if(!isEmpty()){
            dq.pop_front();
        }
    }
    
    void pop_max(){
        if(!isEmpty()){
            dq.pop_back();
        }
    }
    
    int getMin(){
        if(!isEmpty())
            return dq.front();
        else
            return INT_MAX;
    }
    
    int getMax(){
        if(!isEmpty())
            return dq.back();
        else
            return INT_MIN;
    }

    void print(){
        if(!isEmpty()){
            cout<<"deque:";
            for(int i=0;i<(int)dq.size();i++){
                int temp = dq.front();
                cout<<temp<<" ";
                dq.pop_front();
                dq.push_back(temp);
            }
            cout<<endl;
            cout<<getMin()<<" "<<getMax()<<endl;
        }
    }
};

void test(){
    SpecialDeque dq;
    dq.push_min(5);
    dq.push_max(10);
    dq.push_min(3);
    dq.push_max(15);
    dq.push_min(2);
    dq.push_min(1);
    dq.push_max(20);
    dq.push_max(20);
    dq.print();
    dq.push_min(3);
    dq.push_max(16);
    dq.push_min(4);
    dq.print();

}
