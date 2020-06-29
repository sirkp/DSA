// https://practice.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1/?track=SPCF-BitMagic&batchId=154
// gray to binary
// 1) The Most Significant Bit (MSB) of the binary code is always equal to the MSB of the given binary number.
// 2) Other bits of the output binary code can be obtained by checking gray code bit at that index. If current gray code bit is 0, then copy previous binary code bit, else copy invert of previous binary code bit.
int invert(int n){
    if(n==1)
        return 0;
    else
        return 1;    
}

int grayToBinary(int n)
{
    if(n==0)
        return 0;
    int d = ((int)log2(n)+1);
    int no = 0;
    int prev = -1;
    int div;
    for(int i=(d-1);i>=0;i--){
        div = (1<<i);
        if(i==(d-1)){
            no += (div);
            prev = 1;
        }
        else{
            if(((n/div)%2)==0)
            {
                if(prev){
                    no += div;
                }
            }
            else{
                if(!prev){
                    no += div;
                }
                prev = invert(prev);
            }
            
        }
    }
    return no;
}