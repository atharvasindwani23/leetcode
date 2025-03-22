class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> returner;
        sort(arr.begin(), arr.end());
        int minimum = INT_MAX;
        for (unsigned int i  = 0; i < arr.size() - 1; i++) {
           minimum = min(minimum, arr[i + 1] - arr[i]);
        }
        for (unsigned int i  = 0; i < arr.size() - 1; i++) {
            vector<int> temp(2);
            if (arr[i + 1] - arr[i] == minimum) {
                temp[1] = arr[i + 1];
                temp[0] = arr[i];
                returner.push_back(temp);
            }
        }
        return returner;
    }
    // [4,2,1,3] -> [1,2], [2,3], [3,4]
    //[] -> [[]]
    // [4,4,1,3] -> [4,4]
    //sorting algorithm
    //inbuilt sort() -> sort(arr.begin(), arr.end())
    // [1,2,3,4] -> O(n) -> k
    // O(n) [arr[i + 1] - arr[i] == k] -> O(nlogn) -> one sorting algorithm and two loops
    // O(n) -> vector elements in
};
