// https://practice.geeksforgeeks.org/problems/naive-pattern-search-1587115620/1/?track=SPC-Strings&batchId=154
bool isPresent(string s, string pat, int j){
    if(s.substr(j, pat.size())==pat)
        return true;
    else
        return false;    
}

bool search(string pat, string s) { 
	for(int i=0;i<=(s.size()-pat.size());i++)
        if(isPresent(s, pat, i))
            return true;
    return false;        
}