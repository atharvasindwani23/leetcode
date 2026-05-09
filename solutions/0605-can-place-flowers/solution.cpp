class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowers, int n) {
        int count = 0;

    if (flowers.size() == 1 && flowers[0] == 0 && n == 1) {
        return true;
    }
     if (flowers.size() == 1 && flowers[0] == 0 && n == 0) {
        return true;
    }
    for (int i = 0; i < flowers.size(); i++) {
        int flower = flowers[i];
        if (flower == 1) {
            continue;
        }
        if (i == 0 && flowers[i + 1] == 0) {
            flowers[0] = 1;
            count++;
        }

        else if (i > 0 && i == flowers.size() - 1 && flowers[i - 1] == 0) {
            flowers[flowers.size() - 1] = 1;
            count++;
        }
        else if (i > 0 && i < flowers.size() - 1 && flowers[i - 1] == 0 && flowers[i + 1] == 0) {
             flowers[i] = 1;
             count++;
         }
    }
    return count >= n;
    }
};
