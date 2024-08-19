#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumMulti(std::vector<int>& arr, int target) {
        const int MOD = 1000000007;
        long count = 0;
        std::sort(arr.begin(), arr.end());

        for (unsigned int i = 0; i < arr.size(); i++) {
            int start = i + 1;
            int end = arr.size() - 1;
            while (start < end) {
                int sum = arr[i] + arr[start] + arr[end];
                if (sum < target) {
                    start++;
                } else if (sum > target) {
                    end--;
                } else {
                    if (arr[start] == arr[end]) {
                        // If arr[start] == arr[end], there are (end - start + 1) choose 2 pairs
                        count += (end - start + 1) * (end - start) / 2;
                        count %= MOD;
                        break;
                    } else {
                        // Count the number of occurrences of arr[start] and arr[end]
                        int startCount = 1, endCount = 1;
                        while (start + 1 < end && arr[start] == arr[start + 1]) {
                            startCount++;
                            start++;
                        }
                        while (end - 1 > start && arr[end] == arr[end - 1]) {
                            endCount++;
                            end--;
                        }
                        count += startCount * endCount;
                        count %= MOD;
                        start++;
                        end--;
                    }
                }
            }
        }

        return static_cast<int>(count);
    }
};

