// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = lruMap.find(key);
        if(it == lruMap.end()) {
            return -1;
        } else {
            auto pair = *lruMap[key];
            lruList.erase(lruMap[key]);
            lruList.push_front(pair);
            lruMap[key] = lruList.begin();

            return pair.second;
        }
    }
    
    void put(int key, int value) {
        auto it = lruMap.find(key);
        if(it == lruMap.end()) {
            if((lruList.size()) == size) {
                auto &pair = lruList.back();
                lruMap.erase(pair.first);
                lruList.pop_back();
            } 
        } else {
            lruList.erase(lruMap[key]);
        }

        lruList.push_front(make_pair(key, value));
        lruMap[key] = lruList.begin();
    }

    int size;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int, int>>::iterator> lruMap;
};
