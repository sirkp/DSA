int maxWater(int arr[], int n) { 
    if(n<=2)
        return 0;
    else{
        int maxx = 0, c = 0;
        int l = 0, r = (n-1);
        
        while((r-l)>1){
            c = min(arr[l], arr[r])*(r-l-1);
            
            if(c>maxx)
                maxx = c;
            if(arr[l]<arr[r])
                l++;
            else
                r--;
        }
        return maxx;
    }    
} 
