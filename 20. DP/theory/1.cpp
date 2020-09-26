// Memorisation Top down
int fib(int n, vector<int> memory){
    if(n==1||n==0)
        return n;
    
    if(memory[n]==-1)
        memory[n] = fib(n-1, memory)+fib(n-2, memory);
    
    return memory[n];
}