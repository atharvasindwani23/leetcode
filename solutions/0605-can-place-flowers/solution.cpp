class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            return (flowerbed[0] == 0 && n == 1 || flowerbed[0] == 1 && n == 0 || flowerbed[0] == 0);
        }
        int c = 0;
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            c++;
            flowerbed[0] = 1;
        }
        for (unsigned int i  = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                c++;
            }
        }
        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0) {
            c++;
        }
        std::cout << c;
        return (c >= n);
     }
};
