// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/?track=SPC-Strings&amp;batchId=154
void reverseString(char *s, int low, int high){
    for(int i=0;i<((high-low)/2);i++){
        swap(s[i+low], s[high-1-i]);
    }
}

void reverseWords(char *s){
    int i = 0;
    while(s[i]!='\0')
        i++;
    int n = i;

    reverseString(s, 0, n);
    int low = 0, high = 0;

    for(int i=0;i<n;i++){
        low = i;
        while(s[i]!='.' && i<n)
            i++;
        high = i; 
        reverseString(s, low, high);    
    }
    cout<<s;
}
