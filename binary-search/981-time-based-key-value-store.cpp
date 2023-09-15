// https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto it = timeMap.find(key);
        if(it == timeMap.end()) {
            deque<pair<string, int>> l;
            l.push_back({value, timestamp});
            timeMap[key] = l;
        } else {
            it->second.push_back({value, timestamp});
        }
    }
    
    string get(string key, int timestamp) {

        auto it = timeMap.find(key);
        if(it == timeMap.end()) {
            return "";
        }

        auto &l = it->second;
        int low=0, high=l.size()-1;

        string result;
        while(low <= high) {
            int mid = (low + high)/2;

            if(l[mid].second == timestamp) {
                return l[mid].first;
            }

            if(l[mid].second <= timestamp) {
                result = l[mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }

    unordered_map<string, deque<pair<string, int>>> timeMap;
};
