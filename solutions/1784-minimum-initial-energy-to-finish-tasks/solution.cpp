class Solution {
public:
    
    int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);  // sort by buffer ascending
    });

    int energy = 0, initial = 0;
    for (auto& t : tasks) {
        if (energy < t[1]) {
            initial += (t[1] - energy);
            energy = t[1];
        }
        energy -= t[0];
    }
    return initial;
}
    //o(N) * (sum of all - max)


    //the result will always be >= max(all i over tasks[i][2])

};
