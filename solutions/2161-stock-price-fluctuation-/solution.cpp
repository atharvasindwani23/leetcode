class StockPrice {
public:
    unordered_map<int,int> ts2price;
    map<int,int> priceCount;   // sorted by price
    int latestTs = 0;

    void update(int timestamp, int price) {
        latestTs = max(latestTs, timestamp);

        auto it = ts2price.find(timestamp);
        if (it != ts2price.end()) {
            int old = it->second;
            // remove old price from multiset-count
            if (--priceCount[old] == 0) priceCount.erase(old);
        }

        ts2price[timestamp] = price;
        priceCount[price]++;   // add new price
    }

    int current() {
        return ts2price[latestTs];
    }

    int maximum() {
        return priceCount.rbegin()->first;
    }

    int minimum() {
        return priceCount.begin()->first;
    }
};

