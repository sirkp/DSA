// https://practice.geeksforgeeks.org/problems/max-and-second-max/1/?track=SPCF-Arrays&batchId=154
vector<int> largestAndSecondLargest(int n, int arr[]){
    int max = -1, max2= -1;
     for(int i=0;i<n;i++){
        if(arr[i]>max){
            max2 = max;
            max = arr[i];
        }else if(arr[i]>max2 && arr[i]!=max){
            max2 = arr[i];
        }    
     }
     
     vector<int> v{max, max2};
     return v;
}