// https://practice.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1/?track=SPCF-Matrix&batchId=154
void print(int arr[][100],int n)
{
    int j=0;
    bool forward = true;
    for(int i=0;i<n;i++){
        while((forward && j<n)||((!forward) && j>=0)){
            cout<<arr[i][j]<<" ";
            if(forward)
                j++;
            else
                j--;
        }
        if(forward){
            forward = false;
            j = (n-1);
        }else{
            forward = true;
            j = 0;
        }
    }
}
