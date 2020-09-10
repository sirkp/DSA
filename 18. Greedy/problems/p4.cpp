// https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/1/?track=DSASP-Greedy&batchId=154
string largestNumber(int n, int sum){
    if(sum>(n*9))
        return "-1";

    string no="";
    for(int i=0;i<n;i++){
        char c;
        if(sum>9){
            c = '9';
            no += c;
            sum -= 9;
        }else{
            c = '0' + sum;
            no += c;
            sum = 0;
        }
    }
    return no;
}