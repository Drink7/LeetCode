class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back({timestamp, value});
    }
    
    // foo, {1, bar}
    // get foo, 1
    // get foo, 3
    // foo, {4, bar2}
    // get foo, 4
    string get(string key, int timestamp) {
        // key, value, timestamp
        // Returns a value such that set was called previously, with timestamp_prev <= timestamp
        // if timestamp same, return the largest timestamp
        // find last timestamp_prev <= timestamp
        // unordered_map<int, vector<pair<int, int>>> dict;
        // TC: O(m), m operations
        // SC: O(n)
        if (dict.count(key) > 0) {
            auto& timeArr = dict[key];
            int left = 0;
            int right = timeArr.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (timeArr[mid].first <= timestamp) {
                    if (mid == timeArr.size() - 1 || timeArr[mid + 1].first > timestamp) {
                        return timeArr[mid].second;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    right = mid - 1;
                }
            }
        }
        return "";
    }
private:
    //unordered_map<string, vector<pair<int, string>>> dict;
    unordered_map<string, vector<pair<int, string>>> dict;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */