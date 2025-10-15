class FrequencyTracker {
public:
    unordered_map<int, int> mp;   //store number & frequency count
    unordered_map<int, unordered_set<int>> mps; //store frequency & set of number whose frequecny is same
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number) != mp.end()){
            int f = mp[number];
            mps[f].erase(number);
        }
        mp[number]++;
        mps[mp[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if(mp.find(number) != mp.end() && mp[number] > 0){
            int f = mp[number];
            mps[f].erase(number);
            mp[number]--;
            if(mp[number]){
                mps[mp[number]].insert(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return (mps[frequency].size() > 0);
    }
};
