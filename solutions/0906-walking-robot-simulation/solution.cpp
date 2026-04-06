class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        unordered_set<long long> obs;

        // encode (x, y) into one number
        auto encode = [](int x, int y) {
            return ((long long)x << 32) | (unsigned int)y;
        };

        for (auto &o : obstacles) {
            obs.insert(encode(o[0], o[1]));
        }

        // 0=N, 1=E, 2=S, 3=W
        vector<pair<int,int>> dirVec = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int dir = 0;
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {

            if (cmd == -1) {
                dir = (dir + 1) % 4; // right
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4; // left
            }
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dirVec[dir].first;
                    int ny = y + dirVec[dir].second;

                    if (obs.count(encode(nx, ny))) {
                        break;
                    }

                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};
