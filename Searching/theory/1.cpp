//my lowerBound function
// modified p8 to lowerBound
int utilLower(int arr[], int i, int j, int x, int index, bool isPresent){
    if(i<=j){
        int mid = (i+j)/2;
        if(x==arr[mid]){
            isPresent = true;
            index = mid;
        }

        if(x<=arr[mid])
            return utilLower(arr, i, (mid-1), x, index, isPresent);
        else{
            if(!isPresent)
                index = mid;
            return utilLower(arr, (mid+1), j, x, index, isPresent);
        }
    }
        return index;
}

int lowerBound(int arr[], int n, int x){
   return utilLower(arr, 0, (n-1), x, -1, false);
}