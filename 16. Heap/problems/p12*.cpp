// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1/




// with balanceHeaps(Jabarjasti :) )
void FindMedian::insertHeap(int &x){
    if((max.size()+min.size())%2==0){
        if(!min.empty() && min.top()<x){
            balanceHeaps();

            min.push(x);
        }else{
            max.push(x);
        }
        median = max.top();
    }else{
        if(max.top()>x){
            balanceHeaps();

            max.push(x);
        }else{
            min.push(x);
        }
        median = (double)(min.top()+max.top())/2;
    }
}

void FindMedian::balanceHeaps(){
    if((max.size()+min.size())%2==0){
        max.push(min.top());
        min.pop();
    }else{
        min.push(max.top());
        max.pop();
    }
}

double FindMedian::getMedian(){
    return median;
}


// without balanceHeaps
void FindMedian::insertHeap(int &x){
    if((max.size()+min.size())%2==0){
        if(!min.empty() && min.top()<x){
            max.push(min.top());
            min.pop();

            min.push(x);
        }else{
            max.push(x);
        }
        median = max.top();
    }else{
        if(max.top()>x){
            min.push(max.top());
            max.pop();

            max.push(x);
        }else{
            min.push(x);
        }
        median = (double)(min.top()+max.top())/2;
    }
}

void FindMedian::balanceHeaps(){

}

double FindMedian::getMedian(){
    return median;
}
