class ExamTracker {
public:
    map<int, long long> timeToScore;  // prefix sums

    void record(int time, int score) {
        long long cumulative = score;

        auto it = timeToScore.lower_bound(time);
        if (it != timeToScore.begin()) {
            auto prev = std::prev(it);
            cumulative += prev->second;
        }

        timeToScore[time] = cumulative;
    }

    long long totalScore(int startTime, int endTime) {
        if (timeToScore.empty()) return 0;

        auto upper = timeToScore.upper_bound(endTime);
        if (upper == timeToScore.begin()) return 0;
        upper--;

        long long right = upper->second;
        long long left = 0;

        auto lower = timeToScore.lower_bound(startTime);
        if (lower != timeToScore.begin()) {
            auto prev = std::prev(lower);
            left = prev->second;
        }

        return right - left;
    }
};

