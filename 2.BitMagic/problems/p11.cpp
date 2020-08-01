// https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1
int maxAND(int arr[], int n){
    int maxx = -1;
    for(int i=0;i<n;i++)//O(n)
        if(arr[i]>maxx)
            maxx = arr[i];

    int d =  ((int)log2(maxx));  
    
    int m = 0;
    int div;
    
    int c = 0;
    for(int i=0;i<n;i++){// O(n)
            if(arr[i]>=(1<<d))
                c++;
        }


    for(int i = d;i>=0;i--){// O(log)
        div = (1<<i);
        
        int temp;
        if(c<=1){//O(n)
            c = 0;
            for(int i=0;i<n;i++){
                if(arr[i]>=div)
                    arr[i] -= div;
                if(arr[i]>=(div/2))
                    c++;    
            }
            temp = 0;    
        }
        else{
            c = 0;
            for(int i=0;i<n;i++){
                arr[i] -= div;
                if(arr[i]<0)
                    arr[i] = 0;
                if(arr[i]>=(div/2))
                    c++;    
            } 
            temp = div;  
        }
        m += temp;
    }
    return m;
}
