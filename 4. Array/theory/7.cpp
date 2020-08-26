// https://practice.geeksforgeeks.org/problems/longest-consecutive-1s/0
int maxCons1(int N){
    int max = 0;
    int count = 0;
    while(N!=0){
        if(N%2==1){
            count++;
        }
        else{
            if(count>max)
            max = count; 
            
            count = 0;
        }
        N = N/2;
    }
    if(count>max)
    max = count;
    return max;
}