#include <bits/stdc++.h>
using namespace std;

int main(void) {

    return 0;
}

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    list<pair<int, int>> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it == map.end())
            return -1;
        else {
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it == map.end()) {
            if(this->capacity == cache.size()) {
                map.erase(cache.back().first);
                cache.pop_back();

                cache.emplace_front(pair<int, int>(key, value));
                map[key] = cache.begin();
            } else {
                cache.emplace_front(pair<int, int>(key, value));
                map[key] = cache.begin();
            }
        } else {
            it->second->first = key;
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */