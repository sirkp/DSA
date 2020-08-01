// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/?track=SPCF-Searching&batchId=154
void subarraySum(int arr[], int n, int sum){
    
    int i=0, j=0;
    long long int s = 0;

    bool solFound = false;
    while(i<n && j<n){
        if(arr[j]>sum){
            s = 0;
            j++;
            i = j;
        }
        else{
            if((s+arr[j])>sum){// updating prev index
                while((s+arr[j])>sum){
                    s -= arr[i];
                    i++;
                }
            }
            s += arr[j];
            if(s==sum){
                solFound = true;
                break;
            }
            j++;
        }
    }
    if(solFound)
        cout<<(i+1)<<" "<<(j+1);
    else
        cout<<-1;    
    
}
