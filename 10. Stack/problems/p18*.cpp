// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

int _stack :: getMin(){
    if(s.size()!=0)
        return minEle;
    else   
        return -1;
}

int _stack ::pop(){
    if(s.size()!=0){
        int temp = max(minEle, s.top());
        if(s.top()<minEle){
            minEle = 2*minEle - s.top();
        }
        s.pop();
        return temp;
    }else
        return -1;
        
}

void _stack::push(int x){
   if(s.size()==0){
       s.push(x);
       minEle = x;
   }else{
       if(x<minEle){
           s.push(2*x-minEle);
           minEle = x;
       }else{
           s.push(x);
       }
   }
}