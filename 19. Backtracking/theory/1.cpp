// all permutation of a string such that AB is not together
void permutation(string str, int l, int r){
    if(l==r){
        cout<<str<<endl;
        return;
    }

    for(int i=l;i<r;i++){
        swap(str[l], str[i]);
        
        if(!(l!=0 && str[l]=='B' && str[l-1]=='A'))
            permutation(str, l+1, r);
        
        swap(str[l], str[i]);
    }
}

void allPermutation(string str){
    permutation(str, 0, (int)str.size());
}