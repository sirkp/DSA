// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?track=SPCF-Arrays&batchId=154
int equilibriumPoint(long long arr[], int n) {
    
    long long total = 0;
    for(int i=0;i<n;i++)
    total += arr[i];
    
    int sum = 0;
    
    for(int i=0;i<n;i++){
        if(sum == (total-arr[i]-sum))
        return (i+1);
        sum += arr[i];
    }
    
    return -1;
}