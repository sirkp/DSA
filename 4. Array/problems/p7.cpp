// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1/?track=SPCF-Arrays&batchId=154
void swap(vector<long long>& v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void reverse(vector<long long>& arr, int start, int end){// [start, end]
    while(start<end){
        swap(arr, start, end);
        start++;
        end--;
    }
}

int getEnd(int i, int k, int n){
    if((i+k)<n)
        return (i+k-1);
    else
        return (n-1);    
}

vector<long long> reverseInGroups(vector<long long> arr, int n, int k){
    int i=0;
    int end;
    while(i<n){
        end = getEnd(i, k, n);
        reverse(arr, i, end);
        i = end+1;
    }
    return arr;
}