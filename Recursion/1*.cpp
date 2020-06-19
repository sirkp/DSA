// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
string swap(string s,int i, int j){
    char c = s[j];
    s[j] = s[i];
    s[i] = c;
    return s;
}

void printPermutation(string s, int counter){
    for(int i=counter;i<(int)s.size();i++){
        s = swap(s, i, counter);
        if(counter == (s.size()-1))
        cout<<s<<" ";
        printPermutation(s, counter+1);
    }
}