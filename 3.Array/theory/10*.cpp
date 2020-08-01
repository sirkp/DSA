// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0
int reverseKadane(int arr[], int n){
    int total = 0;
    int m = INT_MAX;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        total += arr[i];
        if(sum>0)
        sum=0;

        sum += arr[i];
        if(sum<m)
        m=sum;
    }
    if(total!=m)
    return (total-m);
    else
    return total;
}

int kadaneAlgo(int arr[], int n){
    int m = INT_MIN;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        if(sum<0)
        sum=0;
        
        sum += arr[i];
        if(sum>m)
        m=sum;
    }
    return max(m, reverseKadane(arr, n));
    
}