// https://practice.geeksforgeeks.org/problems/count-element-occurences/1/?track=SPCF-Searching&batchId=154

int countOccurence(int arr[], int n, int k) {
    int max = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }
    int hash[max+1] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int c = 0;
    for(int i=0;i<=max;i++){
        if(hash[i]>(n/k))
            c++;
    }
    return c;
}