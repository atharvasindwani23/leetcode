class FrequencyTracker {
public:
    unordered_map<int, int> freq;      // number -> frequency
    unordered_map<int, int> freqCount; // frequency -> how many numbers have this frequency

    FrequencyTracker() {}

    void add(int number) {
        int oldFreq = freq[number];
        if (oldFreq > 0) freqCount[oldFreq]--;
        freq[number]++;
        freqCount[freq[number]]++;
    }

    void deleteOne(int number) {
        if (!freq.count(number) || freq[number] == 0) return;

        int oldFreq = freq[number];
        freqCount[oldFreq]--;

        freq[number]--;
        if (freq[number] > 0)
            freqCount[freq[number]]++;
    }

    bool hasFrequency(int frequency) {
        return freqCount[frequency] > 0;
    }
};

