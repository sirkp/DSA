// https://practice-stage.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences/0

void twoOdd(int arr[], int n){
    int xor2 = 0;
    for(int i=0;i<n;i++){
        xor2 = xor2^arr[i];
    }

    int setBitNo = xor2 & (~(xor2-1));
    int x = 0;
    int y = 0;
    for(int i=0;i<n;i++){
        if(arr[i]&setBitNo)
            x = x^arr[i];
        else
            y = y^arr[i];    
    }

    if(x>y)
        cout<<x<<" "<<y<<endl;
    else    
        cout<<y<<" "<<x<<endl;
}
