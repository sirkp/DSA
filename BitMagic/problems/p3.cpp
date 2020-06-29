// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1/?track=SPCF-BitMagic&batchId=154
bool checkKthBit(int n, int k){
    n = n>>k;
    if(n&1)
        return true;
    else
        return false;
}