// https://practice.geeksforgeeks.org/problems/primality-test/1/?track=SPCF-Mathematics&batchId=154
bool isPrime(int n)
{
    //Your code here
    bool isPrime = true;
    for(int i=2;i<=int(sqrt(n));i++){
        if(n%i==0){
            isPrime = false;
            break;
        }
    }
    if(isPrime && n!=1)
    return true;
    else
    return false;
}