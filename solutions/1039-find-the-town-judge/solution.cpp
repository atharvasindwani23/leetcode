class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> indegree(n + 1, 0);
    vector<int> outdegree(n + 1, 0);

    for (auto& t : trust) {
        int a = t[0], b = t[1];
        outdegree[a]++;
        indegree[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            return i;
        }
    }

    return -1;
}

    //make a directional map, only doubt which i have which i would ask in an interview is if one person is allowed to trust more than one person
};
