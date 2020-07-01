// https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1/?track=SPCF-Matrix&amp;amp;batchId=154
int search( int m,int n, int x, int arr[SIZE][SIZE])
{
   int i=0, j=n-1;
   while(i<m && j>=0){
       if(arr[i][j]==x)
            return 1;
        if(x<arr[i][j])
            j--;
        else
            i++;
   }
   return 0;
}   