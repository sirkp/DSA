// https://practice.geeksforgeeks.org/problems/deque-deletion/1/?track=DSASP-Deque&batchId=154
void eraseAt(deque <int> &dq, int x){
    if(x<(int)dq.size()){
        dq.push_back(-1);
        int temp;
        for(int i=0;i<=x;i++){
            temp = dq.front();
            dq.pop_front();
            if(i!=x)
                dq.push_back(temp);
        }
        
        while(dq.back()!=-1){
            temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
        dq.pop_back();
    }    
}

void eraseInRange(deque<int> &dq, int start, int end){
    int n = (int)dq.size();
    if(start>=0 && start<n && end>start && end<n){
        dq.push_back(-1);
        int temp;
        for(int i=0;i<end;i++){
            temp = dq.front();
            dq.pop_front();

            if(i<start)
               dq.push_back(temp); 
        }

        while(dq.back()!=-1){
            temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
        dq.pop_back();
    }
}

void eraseAll(deque<int> &dq){
    while(!dq.empty()){
        dq.pop_front();
    }
    
}
