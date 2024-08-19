class Solution {
public:
   bool canReorderDoubled(vector<int>& arr) {
   std::map<int, int> freq;
   for (unsigned int i : arr) {
      freq[i]++;
   }
sort(arr.begin(), arr.end(), [](int i, int j) { return abs(i) < abs(j); });
   for (int i : arr) {
    std::cout << i;
   }
   for (int i : arr) {
    if (freq[i] == 0) {
        continue;
    }
    if (freq[2 * i] == 0) {
        return false;
    }
    freq[i]--;
    freq[2 * i]--;
   }
   return true;
   }
};
