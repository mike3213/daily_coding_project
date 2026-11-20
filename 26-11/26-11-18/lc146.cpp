#include <bits/stdc++.h>
using namespace std;
int main(void) {
    
    return 0;
}

class LRUCache {
private:
    int capacity;
    unordered_map<int, int> map;
    list<pair<int, int>> ls;
public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        } else {
            //ls.splice();
            return map[key];
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            map[key] = value;
        } else {
            if(map.size() + 1 <= this->capacity) {
                map[key] = value;
            } else {
                ls.pop_back();
                ls.emplace_front(pair<int, int>(key, value));
            }
        }
    }
};