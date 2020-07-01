// https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1/?track=SPCF-Matrix&batchId=154
void transpose( int arr[][N],int n) 
{ 
	for(int i=0;i<n;i++){
	    int j=0;
	    int temp;
	    while(i>j){
	        temp = arr[i][j];
	        arr[i][j] = arr[j][i];
	        arr[j][i] = temp;
	        j++;
	    }
	}
}