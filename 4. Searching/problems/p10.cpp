// https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1/?track=SPCF-Searching&batchId=154
void twoRepeated(int arr[], int M){
    int n = M+2;
    
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])]<0)
            cout<<abs(arr[i])<<" ";
        else{
            arr[abs(arr[i])] *= (-1);
        }

    }
}