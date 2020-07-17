// https://practice.geeksforgeeks.org/problems/bubble-sort/1/?track=SPCF-Sorting&batchId=154
void swap(int& a, int& b){
    a = a+b;
    b = a-b;
    a = a-b;
}


void bubble(int arr[], int i, int n)
{
    // Your code here  
    for(int j=0;j<(n-1-i);j++){
        // cout<<arr[i]<<" "<<arr[(i+1)]<<":  ";
        if(arr[j]>arr[(j+1)]){
            swap(arr[j], arr[(j+1)]);
            // isSwapped = true;
        }
        // printArray(arr,n);
    }
}