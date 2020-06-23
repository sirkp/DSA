// https://practice.geeksforgeeks.org/problems/majority-element/0


int mooreVotingAlgo(int arr[], int n){
    int count = 1;
    int element = arr[0];
    
    for(int i=1;i<n;i++){
        if(element == arr[i]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            element = arr[i];
            count = 1;
        }
    }
    count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==element)
        count++;
    }
    if(count>n/2)
    return element;
    else
    return -1;
    
}

int majorityElement1(int arr[], int n){
    int hash[1000001] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int max = 0;
    int max_index = -1;
    for(int i=0;i<1000001;i++){
        if(hash[i]>max){
            max = hash[i];
            max_index = i;
        }
    }
    if(max>(n/2))
    return max_index;
    else
    return -1;
}

int majorityElement2(int arr[], int n) {
    // int n = (int)arr.size();
    sort(arr, arr+n);
    
    int c = 1;
    int m=0;
    int max_index = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            c++;
        else{
            if(c>m){
                m=c;    
                max_index=arr[i-1];
            }
            
            c=1;
        }
    }
    if(c>m){
        m=c;    
        max_index=arr[n-1];
    }
    if(m>(n/2))
    return max_index;
    else
    return -1;
}
