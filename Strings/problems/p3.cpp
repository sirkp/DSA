// https://practice.geeksforgeeks.org/problems/implement-strstr/1/?track=SPC-Strings&batchId=154
bool isPresent(string s, string pat, int j){
    if(s.substr(j, pat.size())==pat)
        return true;
    else
        return false;    
}

int strstr(string s, string pat) { 
    if(s.size()<pat.size())
        return  -1;
	for(int i=0;i<=(s.size()-pat.size());i++)
        if(isPresent(s, pat, i))
            return i;
    return -1;        
}