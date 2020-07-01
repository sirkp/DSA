// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1/?track=SPCF-Matrix&batchId=154
void boundaryTraversal(int m, int n, int arr[SIZE][SIZE]){
    for(int i=0;i<n;i++)
        cout<<arr[0][i]<<" ";
    for(int i=1;i<m;i++)
        cout<<arr[i][(n-1)]<<" ";
    if(m>1)
        for(int i=(n-2);i>=0;i--)
            cout<<arr[(m-1)][i]<<" ";
    if(n>1)
        for(int i=(m-2);i>0;i--)
            cout<<arr[i][0]<<" ";
}