// https://practice.geeksforgeeks.org/problems/roof-top-1587115621/1/?track=SPCF-Searching&batchId=154
int maxStep(int arr[], int n){
    int maxx = 0;
    int c = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1])
            c++;
        else{
            if(c>maxx)
                maxx = c;
            c = 0;
        }    
    }
    if(c>maxx)
        maxx = c;
    return maxx;    
}