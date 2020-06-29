// https://practice.geeksforgeeks.org/problems/set-bits/0
void getLookupTable(int arr[]){
    for(int i=0;i<256;i++){
        arr[i] = (i%2) + arr[i/2];
    }
}

int countSetBits(int n){
    int lookupTable[256] ={0};
    getLookupTable(lookupTable);
    int count = 0;
    while(n!=0)
    {
        count += lookupTable[n&255];
        n = n>>8;
    }

    return count;
}