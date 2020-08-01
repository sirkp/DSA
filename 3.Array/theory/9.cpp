// https://practice.geeksforgeeks.org/problems/longest-subarray-of-evens-and-odds/1
int maxEvenOdd(int arr[], int n) 
{ 
    int max = 1;
    int count = 1;
    bool prevEven = true;
    if(arr[0]%2==1)
    prevEven = false;
    
    for(int i=1;i<n;i++){
        if((prevEven && arr[i]%2==1) || (!prevEven && arr[i]%2==0)){
            count++;
            prevEven = !prevEven;
        }
        else{
            if(count>max)
                max = count;
            count = 1;
        }
    }
    if(count>max)
        max = count;
    return max;
}