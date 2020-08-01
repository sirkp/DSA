// https://practice.geeksforgeeks.org/problems/modular-multiplicative-inverse-1587115620/1/?track=SPCF-Mathematics&batchId=154
int gcdExtended(int a, int b, int *x, int *y){
    if(a==0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    (*x) = y1 - (b/a)*x1;
    (*y) = x1;
    return gcd;
}

int modInverse(int a, int m)
{
    if (m==1)
    return -1;
    int x,y;
    int gcd = gcdExtended(a, m, &x, &y);
    // cout<<gcd<<"a\n";
    if(gcd!=1)
    return -1;
    
    if(x<0)
    return (x+m)%m;
    else
    return x;
    //Your code here
}