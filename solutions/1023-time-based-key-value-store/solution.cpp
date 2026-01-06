class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, map<int, string>> timestamps;
    void set(string key, string value, int timestamp) {
        timestamps[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto& ordered_timestamps = timestamps[key];

        auto it = ordered_timestamps.upper_bound(timestamp);

        if (it == ordered_timestamps.begin()) {
            return "";
        }
        it--;
        return it->second;
        //upper bound, or lower bound
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
