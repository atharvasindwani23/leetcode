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
        
        auto it = upper_bound(voteTimes.begin(), voteTimes.end(), t);

        it--;


        return leaderAtIndex[it - voteTimes.begin()];
    }
};
