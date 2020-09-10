// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1/?track=DSASP-DP&batchId=154
cpp_int findCatalan(int n) {
    cpp_int catalan[n+1] = {0};
    catalan[0] = 1;
    catalan[1] = 1;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++)
            catalan[i] += catalan[j]*catalan[i-1-j];
    }
    return catalan[n];
    
}

// find catalan using ncr formula method