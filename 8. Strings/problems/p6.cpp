// https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1/?track=SPC-Strings&batchId=154
bool compare(string s1, string s2, int j){
    int i = 0;
    if(j>=s2.size())
            j = 0;
    while(i<s1.size()){
        if(s1[i]!=s2[j])
            return false;
        i++;
        j++;
        if(j>=s2.size())
            j = 0;
    }
    return true;
}

bool areRotations(string s1,string s2){
    if(s1.size()!=s2.size())
        return false;

    for(int i=0;i<s2.size();i++){
        if(s1[0]==s2[i]){
            if(compare(s1, s2, i))
                return true;
        }
    }

    return false;
}
