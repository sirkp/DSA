// https://practice.geeksforgeeks.org/problems/adding-two-matrices3512/1/?track=SPCF-Matrix&batchId=154
void sumMatrix(int n1, int m1, int n2, int m2, int arr1[SIZE][SIZE], int arr2[SIZE][SIZE]){
    
    if(n1==n2 && m1==m2){
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cout<<arr1[i][j]+arr2[i][j]<<" ";
    }    
    else{
        cout<<-1;
    }    
}