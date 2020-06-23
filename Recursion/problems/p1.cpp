// https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1/?track=SPCF-Recursion&batchId=154
void printNos(int N)
{
    //Your code here
    if(N>0){
    printNos(N-1);
    cout<<N<<" ";
        
    }
}