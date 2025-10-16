class ProductOfNumbers {
public:
    vector<int> dp;
    ProductOfNumbers() {
        dp.push_back(1); // base prefix product
    }
    
    void add(int num) {
        if (num == 0) {
            dp.clear();
            dp.push_back(1); // reset
        } else {
            dp.push_back(dp.back() * num);
        }
    }
    
    int getProduct(int k) {
        // If k >= dp.size(), that means we’ve crossed a zero → product is 0
        if (k >= dp.size()) return 0;
        return dp.back() / dp[dp.size() - 1 - k];
    }
};

