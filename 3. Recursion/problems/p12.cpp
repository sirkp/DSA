// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/?track=SPCF-Recursion&batchId=154
void print(string str[], int counter, string s, int N){
    if(s.size()==N){
        cout<<s<<" ";
        return;
    }
    
    for(int i=0;i<(int)str[counter].size();i++){
        print(str, counter+1, s+str[counter][i], N);
    }
}

void possibleWords(int a[],int N)
{
    string str[N];
    for(int i=0;i<N;i++){
        str[i] = arr[a[i]];
    }
    print(str, 0, "", N);
}