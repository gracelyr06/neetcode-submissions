class TimeMap {

private:
    // use key as the key and timestamp and value as the "value"
    unordered_map<string, vector<pair<int, string>>> timeMap;

public:
    TimeMap() {
        
    }
    // same timestamp diff key? 
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
        // timeStamps.push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if (!timeMap.contains(key)) {
            return "";
        }
        vector<pair<int, string>> mp = timeMap[key];
        
        int left = 0; 
        int right = mp.size() - 1;
        int result = 0;
        if (mp[0].first > timestamp) {
            return "";
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (timestamp > mp[mid].first) {
                result = mid;
                left = mid + 1;
            } else if (timestamp < mp[mid].first) {
                right = mid - 1;
            } else {
                return mp[mid].second;
            }
        } 
        return mp[result].second;
    }
};
