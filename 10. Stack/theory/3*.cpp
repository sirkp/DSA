// implement k stack in a array
class KStack{
private:
    int freeTop;
    int* arr;
    int* top;
    int* next;
public:
    KStack(int capacity, int k){
        arr = new int[capacity];
        next = new int[capacity];
        top = new int[k];

        for(int i=0;i<k;i++)
            top[i] = -1;

        for(int i=0;i<(capacity-1);i++)
            next[i] = i+1;
        next[capacity-1] = -1;

        freeTop = 0;
    }

    bool isFull(){
        return (freeTop==-1);
    }

    bool isEmpty(int s){
        return (top[s]==-1);
    }

    void push(int x, int s){
        if(!isFull()){
            int i = freeTop;
            freeTop = next[i];
            arr[i] = x;
            next[i] = top[s];
            top[s] = i;
        }
    }

    int pop(int s){
        if(!isEmpty(s)){
            int i = top[s];
            top[s] = next[i];
            next[i] = freeTop;
            freeTop = i;
            return arr[i];
        }else
            return -1;
    }
};


void test(){
    KStack s(6, 3);
    cout<<s.isEmpty(0)<<endl;
    cout<<s.isEmpty(1)<<endl;
    cout<<s.isEmpty(2)<<endl;
    cout<<s.isFull()<<endl;
    s.push(100, 0);
    s.push(200, 0);
    s.push(300, 0);
    s.push(400, 1);
    s.push(500, 1);
    s.push(600, 2);

    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    cout<<s.pop(0)<<" "<<s.pop(1)<<" "<<s.pop(2)<<endl;
    
}
