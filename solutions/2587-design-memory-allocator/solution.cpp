class Allocator {
public:
    int n;
    set<pair<int,int>> freeBlocks;                 // disjoint free intervals [l, r]
    unordered_map<int, vector<pair<int,int>>> byID; // mID -> allocated intervals

    Allocator(int n): n(n) {
        freeBlocks.insert({0, n-1});
    }

    int allocate(int size, int mID) {
        for (auto it = freeBlocks.begin(); it != freeBlocks.end(); ++it) {
            int l = it->first, r = it->second;
            if (r - l + 1 >= size) {
                int start = l, end = l + size - 1;
                freeBlocks.erase(it);
                if (end < r) freeBlocks.insert({end + 1, r});
                byID[mID].push_back({start, end});
                return start;
            }
        }
        return -1;
    }

    int freeMemory(int mID) {
        auto pos = byID.find(mID);
        if (pos == byID.end()) return 0;  // nothing to free

        int freed = 0;
        for (auto [l, r] : pos->second) {
            freed += (r - l + 1);

            // find insertion point using start only
            auto it = freeBlocks.lower_bound({l, INT_MIN});

            // try merge with left neighbor if adjacent/overlapping
            if (it != freeBlocks.begin()) {
                auto pit = std::prev(it);
                if (pit->second + 1 >= l) {          // adjacency or overlap
                    l = std::min(l, pit->first);
                    r = std::max(r, pit->second);
                    freeBlocks.erase(pit);
                }
            }

            // re-find right neighbor after potential left erase
            it = freeBlocks.lower_bound({l, INT_MIN});
            if (it != freeBlocks.end() && it->first <= r + 1) {  // adjacency or overlap
                r = std::max(r, it->second);
                freeBlocks.erase(it);
            }

            freeBlocks.insert({l, r});
        }
        byID.erase(pos);
        return freed;
    }
};

