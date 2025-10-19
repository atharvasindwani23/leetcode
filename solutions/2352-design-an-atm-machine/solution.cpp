class ATM {
public:
    vector<int> notes = {20, 50, 100, 200, 500};
    vector<int> count;

    ATM() {
        count.assign(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            count[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {
        vector<int> used(5, 0);
        int remaining = amount;

        for (int i = 4; i >= 0; --i) {
            int take = min(count[i], remaining / notes[i]);
            used[i] = take;
            remaining -= take * notes[i];
        }

        if (remaining == 0) {
            for (int i = 0; i < 5; ++i)
                count[i] -= used[i];
            return used;
        }
        return {-1};
    }
};

