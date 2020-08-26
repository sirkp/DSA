// https://leetcode.com/problems/lru-cache/submissions/
class LRUCache{
private:
    list<int> head;
    unordered_map<int, pair<int, list<int>::iterator>> hash;// <key, <val, addr>>
    int capacity;
public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }
    
    int get(int key){
        if(hash.find(key)!=hash.end()){
            head.push_front(key);
            head.erase(hash[key].second);
            hash[key].second = head.begin();
            return hash[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value){
        head.push_front(key);
        if(hash.find(key)==hash.end()){
            hash[key] = make_pair(value, head.begin());
            if(head.size()>capacity){
                hash.erase(head.back());
                head.pop_back();
            }
        }else{
            head.erase(hash[key].second);
            hash[key] = make_pair(value, head.begin());    
        }
    }
};
