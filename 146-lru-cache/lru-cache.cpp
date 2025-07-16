class LRUCache {
public:
    list<int> dll;
    int n;
    unordered_map<int, pair<list<int>::iterator, int>> mp;

    LRUCache(int capacity) {
        n = capacity;    
    }
    
    void pushFront(int key){
        auto deleteAddress = mp[key].first;
        dll.erase(deleteAddress);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        //if the key is present
        if(mp.find(key) != mp.end()){
            pushFront(key);
            return mp[key].second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        //case 1 key is already present in the cache
        if(mp.find(key) != mp.end()){
            pushFront(key);
            mp[key].second = value;
        }
        else{ // not present in the cache
            dll.push_front(key);
            mp[key].first = dll.begin();
            mp[key].second = value;
            n--;
        }

        if(n < 0){ //cache overflow least used will be at the back
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */