// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1/?track=SPC-Strings&batchId=154
bool isAnagram(string s1, string s2){
    int freq[26] = {0};
    for(int i=0;i<s1.size();i++){
        freq[(int)(s1[i]-'a')]++;
    }
    for(int i=0;i<s2.size();i++){
        freq[(int)(s2[i]-'a')]--;
    }

    for(int i=0;i<26;i++)
        if(freq[i]!=0)
            return false;
    return true;        
}