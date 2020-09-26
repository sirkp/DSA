
class Trie{
public:
    Trie* children[26];
    bool isEndOfWord;
    Trie(){
        for(int i=0;i<26;i++)
            children[i] = NULL;
        
    }
}