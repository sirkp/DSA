// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/?track=SPCF-Matrix&batchId=154
void  boundaryTraversal(int arr[SIZE][SIZE], int m, int n, int s){
    for(int i=s;i<(n-s);i++){// right
        cout<<arr[s][i]<<" ";
    }
    
    for(int i=(s+1);i<(m-s);i++){// down
        cout<<arr[i][(n-1-s)]<<" ";
    }
    
    if((m-(2*s))>1)
        for(int i=(n-2-s);i>=s;i--){// left
            cout<<arr[(m-1-s)][i]<<" ";
        } 
    if((n-(2*s))>1)
        for(int i=(m-2-s);i>s;i--){// up
            cout<<arr[i][s]<<" ";
        }
}

void spirallyTraverse(int m, int n, int arr[SIZE][SIZE]){
    int s = 0;
    int d = min(m,n);
    
    while(s<((d+1)/2)){
        boundaryTraversal(arr, m, n, s);
        s++;
    }
}
