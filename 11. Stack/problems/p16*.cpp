// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/?track=SPC-Stack&batchId=154
int getId(int arr[MAX][MAX], int n){
    int a = 0, b = n-1;
    while(a<b){
        if(arr[a][b])
            a++;
        else
            b--;
    }
    
    for(int i=0;i<n;i++){
        if(arr[a][i] || (i!=a &&!arr[i][a]))
            return -1;
    }
    return a;
}
