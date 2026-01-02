class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, map<int,string>> timemaps;
    void set(string key, string value, int timestamp) {
        timemaps[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = timemaps[key].upper_bound(timestamp);
        if (it == timemaps[key].begin()) {
            return "";
        }
        it--;
        int time = it->first;
        return timemaps[key][time];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
