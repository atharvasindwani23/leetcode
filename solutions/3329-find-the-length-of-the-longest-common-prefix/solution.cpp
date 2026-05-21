class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //brute force is to go element by element and then for one particular element iterate through the numbers to find the common prefix;

        //time complexity for that is o(n*m* len(word)); => so this is very very expensive

        //how can i optimize this -> thinking aloud
        //even within a particular array i can start deleting items which are prefixes of other things?

        //EXAMPLE 1,10,100 can be consolidated to just 100
        //that might ake it cleaner, not the correct approach
        // should we approach this via tries maybe?
        //cleaning up both the arrays and then trying it
        //how do we clean up the arrays ->

        unordered_set<int> prefixes;

        for (int num : arr1) {
            while (num != 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }
        int res = 0;
        for (int num : arr2) {
            while (!prefixes.count(num) && num > 0) {
                num /= 10;
            }
            if (num > 0) {
                cout << num << endl;
                res = max(res, (int)log10(num) + 1);
            }
        }

        return res;


    }
};
