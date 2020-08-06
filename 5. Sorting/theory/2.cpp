// bubble sort
// time:O(n) extra_space: no
// stable
void swap(int& a, int& b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void bubbleSort(int arr[], int n){
    for(int i=0;i<(n-1);i++){
        bool isSwapped = false;
        for(int j=0;j<(n-1-i);j++){
            if(arr[j]>arr[(j+1)]){
                swap(arr[j], arr[(j+1)]);
                isSwapped = true;
            }
        }
        if(!isSwapped)
            break;
    }
}