// https://practice.geeksforgeeks.org/problems/number-is-sparse-or-not-1587115620/1/?track=SPCF-BitMagic&batchId=154
bool isSparse(int n){
    
    int count = 0;
    while(n!=0){
        if(n%2)
            count++;
        else
            count =0;
        if(count>1)
            return false;
        
        n = n/2;
        
    }
    return true; 
    
}