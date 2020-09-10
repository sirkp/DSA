// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/?track=DSASP-Greedy&batchId=154
bool compare(Item a, Item b){
    return (((float)a.value/(float)a.weight)>((float)b.value/(float)b.weight));
}

double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr+n, compare);
    double ans = 0;
    int w = 0;

    for(int i=0;i<n && w<W;i++){
        if(arr[i].weight>(W-w)){
            ans += (((float)arr[i].value/(float)arr[i].weight) * (W-w));
            w += W-w;
        }else{
            w += arr[i].weight;
            ans += arr[i].value;
        }
    }
    return ans;
}