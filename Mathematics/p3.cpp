// https://practice.geeksforgeeks.org/problems/quadratic-equation-roots/1/?track=SPCF-Mathematics&batchId=154
void quadraticRoots(int a,int b, int c)
{
   double d = (b*b) - (4*a*c);
   if(d<0)
   cout<<"Imaginary";
   else{
       double r1 = floor(((b*(-1))+sqrt(d))/(2.0*a));
       double r2 = floor(((b*(-1))-sqrt(d))/(2.0*a));
       if(r1>r2){
           cout<<int(r1)<<" "<<int(r2);
       }
       else
       cout<<int(r2)<<" "<<int(r1);
   }