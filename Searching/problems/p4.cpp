// https://practice.geeksforgeeks.org/problems/square-root/1/?track=SPCF-Searching&batchId=154
long long int lowerBound(int i, int j, int x, int sqr){
    if(i<=j){
        long long int mid = (i+j)/2;

        if(x==(mid*mid))
            return mid;
        if(x>(mid*mid)){
            sqr = mid;
            return lowerBound((mid+1), j, x, sqr);
        }else{
            return lowerBound(i, (mid-1), x, sqr);
        }

    }
    else
        return sqr;
}

long long int floorSqrt(long long int x) {
    return lowerBound(1, x, x, -1);
}
