// https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1/?track=SPCF-Arrays&batchId=154
void mark(vector<int>& arr, int v, int i){
    int index = v-1;
    int temp = arr[index];
    if(arr[index]>0){
        arr[index] = -1;
        if(temp>0)
            mark(arr, temp, index);
    }
    else
        arr[index] -= 1;
}

void frequencycount(vector<int>& arr,int n)
{ 
    int temp;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            temp = arr[i];
            arr[i] = 0;
            mark(arr, temp, i);
            
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            arr[i]=0;
        else
            arr[i] *= (-1);    
    }
}
