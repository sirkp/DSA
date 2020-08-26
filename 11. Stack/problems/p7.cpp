// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1/?track=SPC-Stack&batchId=154
void twoStacks :: push1(int x){
    if((top2-top1)>1){
        arr[++top1] = x;
    }
}
   
void twoStacks ::push2(int x){
    if((top2-top1)>1){
        arr[--top2] = x;
    }
}
   
int twoStacks ::pop1(){
    if(top1>=0){
        return arr[top1--];
    }
    return -1;
}

int twoStacks :: pop2(){
    if(top2<size){
        return arr[top2++];
    }
    return -1;
}