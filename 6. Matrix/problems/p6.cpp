// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1/?track=SPCF-Matrix&batchId=154
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

void rotateby90(int n, int arr[][N]){
    
    // Your code here
    transpose(arr, n);
    for(int j=0;j<n;j++){
        for(int i=0;i<(n/2);i++){
            int temp = arr[i][j];
            arr[i][j] = arr[(n-1)-i][j];
            arr[(n-1)-i][j] = temp;
        }
    }
}
