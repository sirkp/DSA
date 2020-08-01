// https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents/0
int maxSumWithoutAdajacent(int arr[], int n){
    int exc_prev = 0, inc_prev = arr[0];

    if(n==1)
        return inc_prev;

    int exc_cur, inc_cur;

    for(int i=1;i<n;i++){
        exc_cur = max(inc_prev, exc_prev);
        inc_cur = arr[i] + exc_prev;
        exc_prev = exc_cur;
        inc_prev = inc_cur;
    }
    return max(inc_cur, exc_cur);
}