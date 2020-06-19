// https://practice.geeksforgeeks.org/problems/count-total-digits-in-a-number/1/?track=SPCF-Recursion&batchId=154
int countDigits(int n)
{
   //Your code here
   if(n==0)
   return 1;
   
   int count = 0;
   while(n!=0){
        count++;
        n = n/10;
   }
   return count;
   
}