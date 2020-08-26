// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// just see the problem where it is used, you were able to solve it without knowing
// what is kadane algo, the algo you came up with is exact the same as kadane
int kadaneAlgo(int arr[], int n){
    int max = INT_MIN;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        if(sum<0)
        sum=0;
        
        sum += arr[i];
        if(sum>max)
        max=sum;
    }
    return max;
}