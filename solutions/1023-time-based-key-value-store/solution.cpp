class TimeMap {
public:
    TimeMap() {
        
    }
    //unordered_map<string, map<int, string>>
    
    unordered_map<string, map<int, string>> records;
    void set(string key, string value, int timestamp) {
        records[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto& x = records[key];

        auto kv = x.upper_bound(timestamp);

        if (x.begin() != kv) {
            kv--;
        } else {
            return "";
        }
        return kv->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
