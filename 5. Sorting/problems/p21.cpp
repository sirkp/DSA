// https://practice.geeksforgeeks.org/problems/merge-three-sorted-arrays-1587115620/1/?track=SPCF-Sorting&batchId=154
void mergeTwo(vector<int>& A, vector<int>& B, int& i, int& j, vector<int>& v){
    int temp;
    int m = (int)A.size();
    int n = (int)B.size();
    while(i<m && j<n){
        temp = min(A[i], B[j]);
        v.push_back(temp);
        if(A[i]==temp)
            i++;
        else
            j++;    
    }
}

void mergeOne(vector<int>& A, int& i, vector<int>& v){
    int temp;
    int n = (int)A.size();
    while(i<n){
        v.push_back(A[i]);
        i++;
    }
}

vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) { 
    int m = (int)A.size();
    int n = (int)B.size();
    int o = (int)C.size();
    vector<int> v;
    v.reserve(m+n+o);
    
    int a=0, b=0, c=0;
    int temp;
    while(a<m && b<n && c<o){
        temp = min(A[a], min(B[b], C[c]));
        v.push_back(temp);
        if(A[a]==temp)
            a++;
        else if(B[b]==temp)
            b++;
        else
            c++;        
    }

    mergeTwo(A, B, a, b, v);
    mergeTwo(A, C, a, c, v);
    mergeTwo(B, C, b, c, v);

    mergeOne(A, a, v);
    mergeOne(B, b, v);
    mergeOne(C, c, v);
    return v;
} 
