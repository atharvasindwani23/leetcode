class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (LIS(i, arr) == 0 || LDS(i, arr) == 0) {
                continue;
            }
            res = max(res, LIS(i, arr) + LDS(i, arr)); 
            cout << i << endl;
            cout << LIS(i, arr) << endl;  
         }
         if (res != 0) {
            res += 1;
         }
        return res;
    }

    int LIS (int idx, vector<int>& arr) {
        int count = 0;
        for (int i  = idx; i >= 1; i--) {
            if (arr[i - 1] < arr[i]) {
                count++;
            } else {
                return count;
            }
        }
        return count;
    }
    int LDS(int idx, vector<int>& arr) {
        int count = 0;
        for (int i  = idx; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                count++;
            } else {
                return count;
            }
        }
        return count;
    }
};
