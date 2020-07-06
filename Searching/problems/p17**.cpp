// https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays/0/?track=SPCF-Searching&batchId=154
int medianTwoSortedArray(int arr1[], int arr2[], int m, int n){//hamesa arr1 chota hoga
    int low = 0, high = m;//high is not (m-1) bcoz hame pure small array ka sum chahiye us case mai jab pura array1 hoga left partition mai
    while(low<=high){
        int posX = (low+high)/2;
        int posY = ((m+n+1)/2)-posX;
        int maxLeftX = (posX!=0)?arr1[(posX-1)]:INT_MIN;
        int minRightX = (posX!=m)?arr1[posX]:INT_MAX;
        
        int maxLeftY = (posY!=0)?arr2[(posY-1)]:INT_MIN;
        int minRightY = (posY!=n)?arr2[posY]:INT_MAX;

        if(maxLeftX<=minRightY && maxLeftY<=minRightX){
            if(((m+n)%2)==0)
                return ((max(maxLeftY, maxLeftX)+min(minRightX, minRightY))/2);
            else
                return max(maxLeftY, maxLeftX);    
        } 
        else if(maxLeftY>minRightX)
            low = posX+1;
        else
            high = posX-1;    
    }
    return -1;// to avoid warning
}
