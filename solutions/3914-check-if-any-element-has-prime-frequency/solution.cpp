class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        std::map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        std::vector<int> frequencies;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            frequencies.push_back(x->second);
        }
        for (int num : frequencies) {
            std::cout << num << std::endl;
            if (primeHelper(num) && num != 1) {
                return true;
            }
        }
        return false;
    }
    bool primeHelper(int num) {
        int returner = 0;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                returner++;
            }
        }
        return (returner < 1);
    }
};
