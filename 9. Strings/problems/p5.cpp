// https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1/?track=SPC-Strings&batchId=154
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

bool isRotated(string s1, string s2){
    // anticlockwise
    if(s1.size()==s2.size()){
        int j = s2.size()-2;
        if(compare(s1, s2, j))
            return true;
        else{// clockwise
            j = 2;
            return compare(s1, s2, j);
        }    
    }else
        return false;
}
