class Solution {
public:
        int numOfWays(int n) {
        long a121 = 6, a123 = 6, b121, b123, mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            b121 = a121 * 3 + a123 * 2;
            b123 = a121 * 2 + a123 * 2;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        return (a121 + a123) % mod;
    }

    //if idx i has a color c; then idx i + 1, i - 1 has to have color !c
    //if idx i has a color c; i/1; i\1 has to have color !c
    
};
