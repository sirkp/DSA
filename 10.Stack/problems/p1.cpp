// https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1/?track=SPC-Stack&batchId=154
#define SIZE 1000
void MyStack :: push(int key){
    if(top<SIZE){
        top++;
        arr[top] = key;
    }
}

int MyStack :: pop(){
    if(top>=0){
        top--;
        return arr[top+1];
    }
}