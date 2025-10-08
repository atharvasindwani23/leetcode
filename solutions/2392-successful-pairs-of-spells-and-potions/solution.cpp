class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> res(spells.size());
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
            long long num = ceil(double(success) / double(spells[i]));
            cout << num << endl;
            res[i] = binarySearch(num, potions);
        }
        return res;
    }


    //got it

    //brute force o(n * m) => can we do it quicker in any way? can sorting help us, yeah it can definitely make things better but in the worst case its still o(mn) can we make it linear in any way?

    // goal is to chieck if spells[i] * potions[j] >= success
    // potions[j] >= sucess/spells[i] 
    //  the above can now be done in log(n)

    int binarySearch(long long num, const vector<int>& potions) {
    int l = 0, r = (int)potions.size() - 1, ans = (int)potions.size();
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (potions[mid] >= num) {
            ans = mid;          // potential first index
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return (int)potions.size() - ans; // count >= num
}

//smallest index would be when it works
};
