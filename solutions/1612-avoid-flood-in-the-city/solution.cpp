class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> last;
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < rains.size(); i++){
            int lake = rains[i];
            if (lake != 0){
                if (last.count(lake)){
                    bool found = false;
                    for (auto it = q.begin(); it != q.end(); it++){
                        if (*it > last[lake]){
                            res[*it] = lake;
                            q.erase(it);
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        return {};
                    }
                }
                res.push_back(-1);
                last[lake] = i;
            } else {
                res.push_back(1);
                q.push_back(i);
            }
        }
        return res;
    }
};
