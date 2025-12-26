class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // prefixN[i] = # of 'N' in customers[0..i-1]
        vector<int> prefixN(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixN[i + 1] = prefixN[i] + (customers[i] == 'N');
        }

        int totalN = prefixN[n];
        int totalY = n - totalN;

        int bestIdx = 0;
        int minPenalty = INT_MAX;

        // closing time i from 0..n
        for (int i = 0; i <= n; i++) {
            int N_before = prefixN[i];             // N in [0, i-1]
            int Y_before = i - prefixN[i];        // Y in [0, i-1]
            int Y_after  = totalY - Y_before;     // Y in [i, n-1]

            int penalty = N_before + Y_after;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestIdx = i;
            }
        }

        return bestIdx;
    }
};

