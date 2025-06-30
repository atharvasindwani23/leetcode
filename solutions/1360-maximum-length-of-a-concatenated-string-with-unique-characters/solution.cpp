class Solution {
public:
    int maxLength(vector<string>& arr) {
        //helper to check/see if there is a match bw two arrays
        string path = "";
        int res = 0;
        dfs(arr, path, 0, res);
        return res;
    }

    void dfs(vector<string>& arr, string path, int idx, int& res) {
        if (unique(path)) {
            res = max(res, (int)path.size());
        }
        if (idx == arr.size() || !unique(path)) {
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, res);
        }
    }

    bool unique(string str) {
        set<char> checker;
        for (char ch : str) {
            if (checker.count(ch)) {
                return false;
            }
            checker.insert(ch);
        }
        return true;
    }


    //[10], [9], [8], [7], [6], [5], [4]
    //concatenation-> the answer should be the sum of the largest two unique strings.
    //
};
