// https://practice.geeksforgeeks.org/problems/nth-number-made-of-prime-digits4319/1/?track=SPC-Strings&batchId=154
int getNo(int n, int d){
    if(d==1){
        int arr[] = {2, 3, 5, 7};
        return arr[n%4];
    }
    int no = getNo((n/(int)pow(4, d-1)), 1);
    no = (no*(int)pow(10, d-1)) + getNo((n%(int)pow(4, d-1)), d-1);
    return no;
}

int primeDigits(int n){
    if(n<5)
        return getNo(n-1, 1);
    else if(n<21)
        return getNo(n-5, 2);
    else if(n<85)
        return getNo(n-21, 3);
    else
        return getNo(n-85, 4);            
}