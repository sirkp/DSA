int minSwap(vector<int>& arr1, vector<int>& arr2) {
        int n1 = 0;
        int s1 = 1;

        int n2, s2;
        for(int i=1;i<(int)arr1.size();i++){
            n2 = INT_MAX;
            s2 = INT_MAX;
            if(arr1[i]>arr1[i-1] && arr2[i]>arr2[i-1]){
                n2 = min(n2, n1);
                s2 = min(s2, s1+1);
            }

            if(arr1[i]>arr2[i-1] && arr2[i]>arr1[i-1]){
                n2 = min(n2, s1);
                s2 = min(s2, n1+1);
            }

            n1 = n2;
            s1 = s2;
        } 
        return ((min(n1, s1)==INT_MAX)?-1:min(n1, s1));
    }
