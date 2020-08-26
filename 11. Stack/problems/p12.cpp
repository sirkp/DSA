// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1/?track=SPC-Stack&batchId=154
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    if( current==sizeOfStack/2 ){
        s.pop();
        return s;
    }
    else{
        int temp = s.top();
        s.pop();
        s = deleteMid(s, sizeOfStack, current+1);
        s.push(temp);
        return s;
    }
}