#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class Allocator {
private:
    unordered_map<int, vector<pair<int,int>>> memoryOccupied;
    set<pair<int,int>> freeBlocks; // renamed from freeMemory to avoid name clash

public:
    Allocator(int n) {
        freeBlocks.insert({0, n - 1});
    }
    
    int allocate(int size, int mID) {
        for (auto it = freeBlocks.begin(); it != freeBlocks.end(); ++it) {
            int lower = it->first;
            int upper = it->second;
            if (upper - lower + 1 >= size) {
                int lower_boundary = lower;
                int upper_boundary = lower + size - 1;

                memoryOccupied[mID].push_back({lower_boundary, upper_boundary});
                freeBlocks.erase(it);

                // Right remainder (we always allocate from the left of the interval)
                if (upper_boundary + 1 <= upper) {
                    freeBlocks.insert({upper_boundary + 1, upper});
                }
                return lower_boundary;
            }
        }
        return -1;
    }
    
    // NOTE: method is now named freeMemory to match your call site (obj->freeMemory(...))
    int freeMemory(int mID) {
        if (!memoryOccupied.count(mID)) return 0;

        vector<pair<int,int>> vec = memoryOccupied[mID];
        int sum  = 0;

        for (int i = 0; i < (int)vec.size(); i++) {
            pair<int,int> flag = vec[i];
            int L = flag.first;
            int R = flag.second;
            sum += (R - L + 1);

            // Find the first free block with start >= L
            auto it = freeBlocks.lower_bound(flag);

            int newL = L;
            int newR = R;

            // Merge with previous if adjacent
            if (it != freeBlocks.begin()) {
                auto lesser = prev(it);
                if (lesser->second + 1 == L) {
                    newL = lesser->first;
                    freeBlocks.erase(lesser);
                }
            }

            // Merge with next if adjacent
            if (it != freeBlocks.end() && it->first == R + 1) {
                auto upper = it;
                newR = upper->second;
                freeBlocks.erase(upper);
            }

            // Insert merged interval
            freeBlocks.insert({newL, newR});
        }

        memoryOccupied.erase(mID);
        return sum; 
    }
};

