class TopVotedCandidate {
public:
    vector<int> voteTimes;
    vector<int> leaderAtIndex;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        voteTimes = times;

        unordered_map<int, int> freq;
        int leader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); i++) {
            freq[persons[i]]++;

            // tie goes to the most recent vote
            if (freq[persons[i]] >= maxVotes) {
                maxVotes = freq[persons[i]];
                leader = persons[i];
            }

            leaderAtIndex.push_back(leader);
        }
    }
    
    int q(int t) {
        int left = 0;
        int right = voteTimes.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (voteTimes[mid] <= t) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return leaderAtIndex[right];
    }
};
