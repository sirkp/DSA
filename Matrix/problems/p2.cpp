// https://practice.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1/?track=SPCF-Matrix&batchId=154
void sumTriangles(int n, int arr[SIZE][SIZE]){
    int up = 0;
    int low = 0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(j>=i)
            up += arr[i][j];
        if(j<=i)
            low += arr[i][j];
    }
    cout<<up<<" "<<low;
}