// all permutation of string
void permutation(string str, int l, int r){
    if(l==r){
        cout<<str<<"\n";
        return;
    }
    for(int i=l;i<r;i++){
        swap(str[l], str[i]);
        permutation(str, l+1, r);
        swap(str[l], str[i]);
    }
}

void allPermutation(string str){
    permutation(str, 0, (int)str.size());
}