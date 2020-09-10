// https://practice.geeksforgeeks.org/problems/black-and-white-1587115620/1
#define MOD 1000000007
int util(int x, int y, int N, int M){
    int c = 0;
    if((x-1)>=0 && (y+2)>=0 && (x-1)<N && (y+2)<M)
        c++;
    if((x+1)>=0 && (y+2)>=0 && (x+1)<N && (y+2)<M)
        c++;
    if((x-1)>=0 && (y-2)>=0 && (x-1)<N && (y-2)<M)
        c++;
    if((x+1)>=0 && (y-2)>=0 && (x+1)<N && (y-2)<M)
        c++;
    
    if((x-2)>=0 && (y+1)>=0 && (x-2)<N && (y+1)<M)
        c++;
    if((x+2)>=0 && (y+1)>=0 && (x+2)<N && (y+1)<M)
        c++;
    if((x-2)>=0 && (y-1)>=0 && (x-2)<N && (y-1)<M)
        c++;
    if((x+2)>=0 && (y-1)>=0 && (x+2)<N && (y-1)<M)
        c++;

    return ((N*M)-1-c);
}
long long solve(int N, int M) {
    long long ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int temp = util(i, j, N, M);
            ans = (ans+temp)%MOD;
        }
    }
    return ans;
}
