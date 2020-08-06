// https://practice.geeksforgeeks.org/problems/operations-on-stack/1/?track=SPC-Stack&batchId=154
void insert(stack<int> &s,int x){
    s.push(x);
}

void remove(stack<int> &s){
    s.pop();
}

void headOf_Stack(stack<int> &s){
    int x=s.top();
    cout<<x<<" "<<endl; 
}

bool find(stack<int> s, int val){
    bool exists=false;
    
    while(!s.empty()&&!exists){
        if(s.top()==val)
            exists = true;
        s.pop();
    }
    
    if(exists==true){
        return true;
    }
    else{
        return false;
    }
}
