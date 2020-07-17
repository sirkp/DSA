// https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1/?track=SPCF-Sorting&batchId=154
int upperBoundUtil(int arr[], int low, int high, int x, int index){
    if(low<=high){
        int mid = (low+high)/2;
        
        if(x>=arr[mid]){
            return upperBoundUtil(arr, (mid+1), high, x, index);
        }else
            index = mid;
            return upperBoundUtil(arr, low, (mid-1), x, index);
    }
    return index;
}

int upperBound(int arr[], int n, int x){
    return upperBoundUtil(arr, 0, (n-1), x, n);
}

long long countPairs(int X[], int Y[], int m, int n){
    sort(Y, Y+n);

    int i = 0;
    int countOne=0, countTwo=0; 
    while(Y[i]<3 && i<n){
        if(Y[i]==1)
            countOne++;
        else if(Y[i]==2)
            countTwo++;    
        i++;    
    }

    long long count = 0;
    for(int i=0;i<m;i++){
        int ind;
        if(X[i]>1){
            if(X[i]==2)
                ind = upperBound(Y, n, 4);
            else
                ind = upperBound(Y, n, X[i]);
            count += n-ind;
            count += countOne;
            if(X[i]==3)
                count += countTwo;
        }
    }
    return count;
}

