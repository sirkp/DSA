// https://practice.geeksforgeeks.org/problems/selection-sort/1
int select(int arr[], int j)
{
    int maxx = -1;
    int max_index = -1;
    for(int i=j;i>=0;i--){
        if(arr[i]>maxx){
            maxx = arr[i];
            max_index = i;
        }
    }  
    return max_index;
    
}