// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1/?track=SPCF-Searching&batchId=154
int majorityElement(int arr[], int n) {
    int p = arr[0];
    int c = 1;

    for(int i=1;i<n;i++){
        if(p==arr[i])
            c++;
        else
            c--;

        if(c==0){
            p = arr[i];
            c = 1;
        }    
    }
    c = 0;
    for(int i=0;i<n;i++)
        if(arr[i]==p)
            c++;
    if(c>(n/2))
        return p;
    else
        return -1;    
}
