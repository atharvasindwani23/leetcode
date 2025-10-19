class ExamTracker {
public:
    map<int, long long> prefixSum;
    long long total = 0;

    void record(int time, int score) {
        total += score;
        prefixSum[time] = total;
    }

    long long totalScore(int startTime, int endTime) {
        if (prefixSum.empty()) {
            return 0;
        }

        long long endSum = 0;
        long long startSum = 0;

        // Find total sum up to endTime
        auto itEnd = prefixSum.upper_bound(endTime);
        if (itEnd != prefixSum.begin()) {
            --itEnd;
            endSum = itEnd->second;
        }

        // Find total sum just before startTime
        auto itStart = prefixSum.lower_bound(startTime);
        if (itStart != prefixSum.begin()) {
            --itStart;
            startSum = itStart->second;
        }

        return endSum - startSum;
    }
};

