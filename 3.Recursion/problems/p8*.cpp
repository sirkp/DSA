// https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1/?track=SPCF-Recursion&batchId=154
bool isLucky(int n, int counter) {
    if(n%counter==0)
    return false;
    
    if(counter>n)
    return true;
    
    return isLucky(n - n/counter, counter+1);
}