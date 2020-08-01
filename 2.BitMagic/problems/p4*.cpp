// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1/?track=SPCF-BitMagic&batchId=154

int getNoOfDigits(int n){
    if(n==0)
        return 0;
    return (log2(n)+1);
}

int optmisedMethod(int n){
    int d = getNoOfDigits(n);
    int total = 0;
    int temp;
    int c;
    for(int i=1;i<=d;i++){
        temp = 1<<i;
        c = (((n+1)/temp)*(temp/2));
        int b = ((n+1)%temp) - (temp/2);
        if(b>0)
            c += b;
        total += c;
    }
    return total;
}

bool isMax(int n, int d){
    if((n&(n+1)))
        return false;
    else
        return true;    
}

int getLessMax(int d){
    d--;
    return ((1<<d)-1);
}

int getBits(int n){
    if(n==0)
        return 0;
    int d = getNoOfDigits(n);
    if(isMax(n, d)){
        int s = 2;
        int count = 1;

        for(int i=2;i<=d;i++){
            count = s + (count*2);
            s = s*2;  
        }
        return count;
    }else{
        int nearestMax = getLessMax(d);
        return (getBits(nearestMax) + (n-nearestMax) + getBits((n-nearestMax-1)));
    }
}

int totalSetBits(int n){
    int total = getBits(n);
    return total;
}

